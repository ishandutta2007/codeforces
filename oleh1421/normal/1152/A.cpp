#include <iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
int a[1000001];
int b[1000001];
int main()
{
    int n,m;cin>>n>>m;
    int cnt1=0;
    for (int i=1;i<=n;i++){
        int  a;cin>>a;
        cnt1+=a%2;
    }
    int cnt2=0;
    for (int i=1;i<=m;i++){
        int  a;cin>>a;
        cnt2+=a%2;
    }
    cout<<min(cnt1,m-cnt2)+min(n-cnt1,cnt2);
    return 0;
}