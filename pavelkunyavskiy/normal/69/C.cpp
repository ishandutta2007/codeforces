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

typedef long long int64;
typedef long double ld;

const int MAXN=200;

map<string,int> number;

int cnt[MAXN][MAXN];
int need[MAXN][MAXN];
int n,m,k;

char s[150*150];

void parse(int num){
    gets(s);
//  cerr << s << endl;
    char* t=s;
    for (;*t != ':';++t);
    number[string(s,t)]=num;
    t+=2;
    for (; *t ;){
        char* t1=t;
        for (;*t != ' ';++t);
//      cerr << string(t1,t) << endl;
        int numb=number[string(t1,t)];
        ++t;
        sscanf(t," %d ",&need[num][numb]);
        for (;*t != 0 && *t != ' ';++t);
        if (*t==' ')
            ++t;
    }       
}

void add(int per,int art){
    cnt[per][art]++;
    for (int i=n;i<n+m;i++){
        bool q = true;
        for (int j=0;j<n && q;j++)
            if (need[i][j] > cnt[per][j])
                q=false;
        if (q){
            for (int j=0;j<n;j++)
                cnt[per][j] -= need[i][j];
            cnt[per][i]++;
            break;
        }
    }
}



int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    string s;
    int q;
    getline(cin,s); 
    sscanf(s.data(),"%d %d %d %d",&k,&n,&m,&q);
    for (int i=0;i<n;i++){
        getline(cin,s);
        number[s] = i;
    }
    
    for (int i=0;i<m;i++)
        parse(i+n);
        
//    return 0;
        
   
    for (int i=0;i<q;i++){
        int to;
        scanf("%d ",&to);
        string s;
        --to;
        getline(cin,s);
        add(to,number[s]);
    }
    
    vector<pair<string,int> > order(number.begin(),number.end());
 //   cerr << order.size() << endl;
    
  //  for (int i=0;i<n+m;i++)
  //    cerr << order[i].first << endl;
  //    
   // return 0;
  
    for (int i=0;i<k;i++){
        int kol=0;
        for (int j=0;j<n+m;j++)
            kol+=(cnt[i][j] != 0);
        printf("%d\n",kol);
        for (int j=0;j<n+m;j++)
            if (cnt[i][order[j].second] != 0)
                printf("%s %d\n",order[j].first.data(),cnt[i][order[j].second]);
    }       
    return 0;
}