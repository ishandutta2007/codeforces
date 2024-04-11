#include <bits/stdc++.h>

using namespace std;
int w;
long long n, k;
pair<long long, long long> o={0, 0};
pair<long long, long long> csop(long long kezd, long long kim) {
    long long sum=0, kov=kezd+k;
    if (kezd<=kim && kim<=kov) {
        kov++;
    }
    sum=(kov-kezd)*(kov-kezd-1)/2;
    if (log(k)+log(kezd)<42.0) {
        sum+=kezd*(kov-kezd);
    } else {
        sum=2e18;
    }
    if (kezd<=kim && kim<kov) {
        sum-=kim;
    }
    return {sum, kov};
}
pair<long long, long long> calc(long long ert) {
    if (ert<=k*(k+1)/2) {
        return {1, k*(k+1)/2};
    }
    long long kis=ert/k-k/2;
    auto s=calc(kis);
    long long fi=s.first, se=s.second;
    long long s2=kis, kor=0, ert2=0;
    s2-=(fi-1)*(k+1), kor+=fi-1, ert2=(fi-1)*(k+1);
    long long ss=(s2+k-2)/k;
    kor+=ss, ert2+=ss*k;
    ert2++, kor++;
    if (ert2>=se) {
        ert2++;
    }
    auto cs=csop(ert2, se);
    if (cs.first<ert) {
        ert2=cs.second, kor++;
        cs=csop(ert2, se);
    }
    return {kor, cs.first};
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        if (n<=k || (k==2 && n<=5)) {
            cout << n << "\n";
            continue;
        }
        auto s=calc(n);
        if (s.second==n) {
            cout << s.first*(k+1) << "\n";
        } else {
            long long fi=s.first, ans=fi*(k+1);
            n-=fi*(k+1)-1;
            ans+=(k+1)*(n/k)+n%k;
            if (n%k==0) {
                ans--;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}