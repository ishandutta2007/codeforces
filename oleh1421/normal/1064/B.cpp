#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[100001];
int main()
{
    int n;cin>>n;
    while (n--){
        int a;cin>>a;
        int cnt=0;
        while (a){
            cnt+=a%2;
            a/=2;
        }
        cout<<(1<<cnt)<<endl;
    }
    return 0;
}