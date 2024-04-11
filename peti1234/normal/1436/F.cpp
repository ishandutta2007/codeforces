#include <bits/stdc++.h>

using namespace std;
long long mod=998244353, o2=499122177;
const int c=100002;
long long n, ans, db[c], bal[c], cnt, sum, add, p1, p2;
long long po(long long a, long long b) {
    long long ans=1;
    while (b) {
        if (b%2) {
            ans*=a, ans%=mod;
        }
        a*=a, a%=mod;
        b/=2;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        db[a]=b;
    }
    bal[1]=1;
    for (int i=1; i<c; i++) {
        cnt=0, sum=0, add=0;
        for (int j=i; j<c; j+=i) {
            cnt+=db[j], sum+=db[j]*j;
        }
        if (cnt==0) {
            continue;
        }
        long long s1=po(2, cnt-1), s2=0;
        if (cnt>1) {
            s2=po(2, cnt-1);
        }
        cnt%=mod, sum%=mod;
        cnt+=mod;

        for (int j=i; j<c; j+=i) {
            if (!db[j]) {
                continue;
            }
            // 2^(cnt-1)*(1+(cnt-1)/2)*i*i*db[i]
            p1=s1*((cnt-1)*o2%mod)%mod*j%mod*j%mod*db[j]%mod;

            //cout << p1 << "\n";
            // 2^(cnt-2)*(2+(cnt-2)/2)*i*db[i]*sum/2
            p2=s2*(1+(cnt-2)*o2%mod)%mod*j%mod*db[j]%mod*(sum-j+mod)%mod*o2%mod;

            //cout << p2 << "\n";

            add+=p1+p2;
            add%=mod;
        }
        //cout << "valt " << i << " " << bal[i] << " " << add << "\n";
        int s=bal[i];
        ans+=add*s;
        for (int j=i; j<c; j+=i) {
            bal[j]-=s;
        }
    }
    cout << (ans%mod+mod)%mod;
    return 0;
}