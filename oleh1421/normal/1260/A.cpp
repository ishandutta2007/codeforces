#include <bits/stdc++.h>
#define endl '\n'
#define inf 1000000000000000001ll
#define lcm my_lcm
#define gcd my_gcd
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        int c,sum;cin>>c>>sum;
        int res=((sum/c)*(sum/c))*(c-sum%c)+(sum%c)*(sum/c+1)*(sum/c+1);
        cout<<res<<endl;
    }
    return 0;
}
/*
1
5 12
1 1
2 2
3 3
4 4
5 5

5 3
1 5
3 4

4 1
2 3
3 1
1 2
*/