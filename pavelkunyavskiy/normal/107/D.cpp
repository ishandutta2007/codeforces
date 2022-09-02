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

const int MOD = 12345;


int a[123][123];
int temp[123][123];
int res[123][123];
int mod[26];
bool good[26][123];
bool can[26];
int modmult;
int n;
int64 st;



void mult(int a[][123],int b[][123]){

//    cerr <<"!!!!!!!!!!!!"<<endl;
//    cerr << a[0][0] <<" "<<a[0][1] <<" "<<a[1][0] <<" "<<a[1][1] << endl;
  //  cerr << b[0][0] <<" "<<b[0][1] <<" "<<b[1][0] <<" "<<b[1][1] << endl;


    for (int i = 0; i < modmult; i++)
        for (int  j = 0; j < modmult; j++)   
                 temp[i][j] = 0;
    for (int i = 0; i < modmult; i++)
        for (int  j = 0; j < modmult; j++) 
            for (int  k = 0; k < modmult; k++) {   
                 temp[i][j] += (a[i][k] * b[k][j]) % MOD;
                 temp[i][j] %= MOD;          
            }


                                
    for (int i = 0; i < modmult; i++)
        for (int  j = 0; j < modmult; j++)  
                a[i][j] = temp[i][j];


//   cerr << a[0][0] <<" "<<a[0][1] <<" "<<a[1][0] <<" "<<a[1][1] << endl;
  // cerr <<"!!!!!!!!!!!!"<<endl;

}



int gennum(int *a){
    int num = 0;
    for (int i = 0; i < 26; i++){   
  //      cerr << "!!!"<<mod[i] << endl;
        num = num * mod[i] + (a[i]+mod[i])%mod[i];
    }
    return num;
}

void genval(int mask,int* a){
    for (int i = 25; i >= 0; i--){  
//        cerr << "???" << mod[i] << endl;
        a[i] = mask % mod[i];
        mask /= mod[i];
    }
}

vector<int> goodmask;

int b[26];


void per(int pos){
    if (pos == 26){
        goodmask.pb(gennum(b));
        return;
    }

    for (int i = 0; i < mod[pos]; i++)
        if (good[pos][i]){
            b[pos] = i;
            per(pos+1);
        }        
}


void gen_next(int mask){
    int temp[26];
    genval(mask,temp);
    for (int i = 0; i < 26; i++)
        if (can[i]) {
            temp[i]++;
            a[mask][gennum(temp)] += 1;
            temp[i]--;
        }
}








int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif 
    cin >> st;
    cin >> n;
    for (int i = 0; i < 26; i++)
        mod[i] = good[i][0] = 1;
    modmult = 1;
    for (int i = 0; i < n; i++){
        char c;
        cin >> c;
        int tmp;
        cin >> tmp;
        mod[c - 'A'] *= tmp;
        can[c - 'A'] = true;
        modmult *= tmp;
        for (int j=0; j < 123;j++)
            good[c - 'A'][j] |= (j%tmp) == 0;
    }


//    for (int i = 0; i < 26; i++)
//        cerr << mod[i] << endl;

    for (int i = 0; i < modmult; i++){
    //   cerr << i << endl;
       gen_next(i);
    }

    //return 0;
    per(0);

    //return 0;

    memset(res,0,sizeof(res));

    
    /*for (int i = 0; i < modmult; i++)
        for (int j = 0; j < modmult; j++)
            cerr << a[i][j] <<" \n"[j==modmult-1];
    cerr << endl;*/


    res[0][0] = 1;
    for (; st != 0; st/=2 ){
        if (st % 2 == 1)
            mult(res,a);
        mult(a,a);


       /* for (int i = 0; i < modmult; i++)
            for (int j = 0; j < modmult; j++)
                cerr << a[i][j] <<" \n"[j==modmult-1];
        cerr << endl;*/


    }

/*    for (int i = 0; i < modmult; i++)
        for (int j = 0; j < modmult; j++)
        cerr << res[i][j] <<" \n"[j==modmult-1];
    cerr << endl;*/


    int ans = 0;
    for (int i = 0; i < goodmask.size();i++){
         ans += res[0][goodmask[i]];
         ans %= MOD;
    }

    cout << ans << endl;
     
    return 0;
}