#include <bits/stdc++.h>

using namespace std;
const int c=1<<18;
int n, rf[c], ki[c], cnt[c];
long long ans;
int holvan(int a) {
    if (ki[a]==-1) {
        return a;
    }
    int x=holvan(ki[a]);
    ki[a]=x;
    return x;
}
int unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a==b) {
        return 0;
    }
    if (rf[a]<rf[b]) {
        swap(a, b);
    }
    int s=1;
    if (rf[a]==1) s+=cnt[a]-1;
    if (rf[b]==1) s+=cnt[b]-1;
    ki[b]=a, rf[a]+=rf[b];
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        ans-=x;
        cnt[x]++;
    }
    for (int i=0; i<c; i++) {
        ki[i]=-1, rf[i]=1;
    }
    cnt[0]++;
    for (int i=c-1; i>0; i--) {
        for (int j=i; j>0; j=((j-1)&i)) {
            if (cnt[i-j] && cnt[j]) ans+=(long long) i*unio(j, i-j);
        }
    }
    cout << ans << "\n";
    return 0;
}