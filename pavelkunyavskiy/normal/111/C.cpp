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

int n,m;

int getcnt(int mask){
    int ans = 0;
    for (int i=0;i<n;i++, mask /= 3)
        ans += ((mask %3) != 2);
    return ans;
}

bool good[1000][1000];
int  cnt[1000];

bool check(int mask1,int mask2){
    int m1[10],m2[10];
    for (int i = 0; i < n; i++)
        m1[i] =mask1%3,mask1/=3;
    for (int i = 0; i < n; i++)
        m2[i] =mask2%3,mask2/=3;

    for (int i = 0; i < n; i++){
        if (m1[i] == 1 && m2[i] != 2)
            return false;
        if (m2[i] == 0){
            if (i && m2[i-1] == 2)
                continue;
            if (i != n-1 && m2[i+1] == 2)
                continue;
            if (m1[i] == 2)
                continue;
            return false;
        }
    }
    return true;
}

bool check(int mask1){
    for (int i = 0; i < n; i++){
        if (mask1 % 3 == 1)
            return false;
        mask1 /= 3;
    }
    return true;        
}


int ans[50][1000];

string conv(int id){
    string res = "";
    for (int i = 0; i < n; i++)
        res += '0' + id%3,id/=3;
    return res;

}



int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    cin >> n >> m;
    if (n > m)
        swap(n,m);

    int cm = 1;
    for (int i = 0; i < n; i++)
        cm *= 3;

    for (int i = 0; i < cm; i++){
        cnt[i] = getcnt(i);
//        cerr << i <<" "<<cnt[i] << endl;
        for (int j = 0; j < cm; j++){
            good[i][j] = check(i,j);
            //if (good[i][j])
              //  cerr << conv(i) <<" -> "<<conv(j) << endl;
        }
    }

    memset(ans,250,sizeof(ans));


    ans[0][0] = 0;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < cm; j++){
//            cerr << i <<" "<<j<<" "<<ans[i][j] << endl;
            for (int k = 0; k < cm; k++)
                if (good[j][k]) {
                //    cerr << "("<<i <<" "<<j<<")"<<" -> "<<i+1 << " "<<k<<" "<<ans[i][j]+cnt[k]<<" "<<cnt[k]<<endl;
                    ans[i+1][k] = max(ans[i+1][k],ans[i][j]+cnt[k]);
                }
        }

    int res = -(1<<30);

    for (int i = 0; i < cm; i++)
        if (check(i)){         
  //          cerr << i << " "<<ans[m][i] <<endl;
            res = max(res,ans[m][i]);
        }

    cout << res << endl;
    return 0;
}