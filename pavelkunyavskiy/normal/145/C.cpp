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


int cnt2;
vector<int> v;
int a[110000];

int dp[1500][1500];

const int MOD = 1000000007;


int pow(int a,int b){
    if (b == 0)
        return 1;
    if (b & 1)
        return (pow(a,b-1) * 1LL * a) % MOD;
    int temp = pow(a,b>>1);
    return (temp *1LL* temp) % MOD;
}

int inv(int a){
    return pow(a,MOD-2);
}

bool luck(int x){
    while (x){
        if (x % 10 != 4 && x % 10 != 7)
            return false;
        x /= 10;
    }
    return true;
}

int c(int n,int k){
    int ans = 1;
    for (int i = k+1; i <= n; i++)
        ans = (ans *1LL* i) % MOD; 
    for (int i = 1; i <= n-k; i++)
        ans = (ans *1LL* inv(i)) % MOD; 
    return ans;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    int k;
    scanf("%d %d",&n,&k);
    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }

    sort(a,a+n);

    for (int i = 0;i < n;){
        if (!luck(a[i])){
            cnt2++;
            i++;
            continue;
        }
        int j = i;
        for (;j < n && a[i] == a[j]; j++);
        v.pb(j-i);
        i = j;    
    }


    sort(v.begin(),v.end());

    dp[0][0] = 1;

    for (int i = 0; i < (int)v.size(); i++)
        for (int j = 0; j <= i; j++){
            dp[i+1][j] = (dp[i+1][j]+dp[i][j]) % MOD;
            dp[i+1][j+1] += (dp[i+1][j+1] + dp[i][j] * 1LL * v[i]) % MOD;
        }

//    cerr << dp[2][0] << " "<<dp[2][1] << " "<<dp[2][2] << endl;

                
    int coef = c(cnt2,k);
    if (cnt2 < k)
        coef = 1;
    int ans = 0;


    for (int i = max(0,k-cnt2); i <= k && i <= (int)v.size(); i++){
//        cerr << i <<" "<<dp[v.size()][i] << " "<<coef <<endl;
        ans = (ans + dp[v.size()][i] * 1LL * coef) % MOD;
        coef = (((coef * 1LL * inv(cnt2-k+i+1)) % MOD) * 1LL * (k-i)) % MOD;
    }          

    cout << ans << endl;
    

    return 0;
}