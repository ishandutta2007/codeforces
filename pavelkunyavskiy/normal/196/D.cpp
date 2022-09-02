#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int _P[3] = {239017,17239,170239};
ull P;
ull INVP;

const int MAXN = 410000;

char rs[MAXN];
char s[MAXN];
ull hash[MAXN];
ull rhash[MAXN];
ull stp[MAXN];
int len;

void inithash(char* s,ull* to){
    to[0] = 0;
    for (int i = 0; s[i]; i++)
        to[i+1] = to[i] + s[i]*stp[i];
}

ull gethash(int l,int r){
    return (hash[r+1] - hash[l]) * stp[MAXN-r-50]; 
}

ull getrhash(int l,int r){
    swap(l,r);
    l = len - l - 1;
    r = len - r - 1; 
    return (rhash[r+1] - rhash[l]) * stp[MAXN-r-50]; 
}


int d;

struct qhasher{
    int l,r;
    ull h;
    ull rh;
    int len;

    qhasher(int len):len(len){
        l = 0, r = 0;
        h = rh = 0;
    }

    void move(){
        h = h + stp[min(r,len)] * s[r];
        rh = rh * P + s[r];
        r++;
        if (r-l > len){
            h -= s[l];
            h *= INVP;
            rh -= s[l] * stp[len];
            l++;
        } 
    }
    bool get(){
        return h == rh;
    }
};


bool checkit(int pos){
    if (pos >= d-1 && s[pos] == s[pos-d+1] && gethash(pos-d+2,pos-1) == getrhash(pos-d+2,pos-1))
        return false;
    if (pos >= d && s[pos] == s[pos-d] && gethash(pos-d+1,pos-1) == getrhash(pos-d+1,pos-1))
        return false;
    return true;      
}



int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #else
    srand(time(NULL));
  #endif
    P = _P[rand()%3];
    INVP = 1;
    {
        ull temp = P;
        for (int i = 0; i < 63; i++){
            INVP = INVP * temp;
            temp = temp * temp;
        }                      
        assert(INVP * P == 1);
    }
    stp[0] = 1;
    for (int i = 1; i < MAXN; i++)
       stp[i] = stp[i-1] * P;

    gets(s);
    sscanf(s,"%d",&d);
    gets(s);
    memcpy(rs,s,sizeof(s));
    reverse(rs,rs+(len = strlen(rs)));

    inithash(s,hash);
    inithash(rs,rhash);


    int first = len-1;

    for (int i = 0; i < len; i++){
        if (i + d <= len && gethash(i,i+d-1) == getrhash(i,i+d-1))
            first = min(first,i+d-1);
        if (i + d < len && gethash(i,i+d) == getrhash(i,i+d))
            first = min(first,i+d); 
    }


    while (first >= 0){
        s[first]++;
        while (s[first] <= 'z' && !checkit(first))
           s[first]++;
        if (s[first] > 'z')
            --first;
        else
            break;
    }

    if (first < 0){
        printf("Impossible\n");
        return 0;
    }

    for (int i = first+1; i < len; i++)
        s[i] = 'a';

    qhasher h1(d-1),h2(d-2);

    for (int i = 0; i < len; i++){
      // cerr << i <<" "<<s<<" "<<h2.l <<" "<<h2.r << " "<<h2.h <<" "<<h2.rh << endl;
       while ((i >= d-1 && h2.get() && (s[i] == s[i-d+1])) || (i >= d && h1.get() && (s[i] == s[i-d])))
          s[i]++;
       h1.move();
       h2.move();        
    }    
    

    s[len] = 0;
    puts(s);   
    return 0;
}