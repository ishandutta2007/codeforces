#include <bits/stdc++.h>

using namespace std;
const int c=400005, f=c/2;
long long ans;
int n, m, ertk[c], prefk[c], cntk=f, ertn[c], prefn[c], cntn=f;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    ertk[f]=prefk[f]=ertn[f]=prefn[f]=1;
    ans=(long long)n*(n+1)/2;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (x<m) cntk++;
        else cntk--;

        prefk[cntk]=prefk[cntk-1]+ertk[cntk];
        ans-=prefk[cntk];
        ertk[cntk]++, prefk[cntk]++;


        if (x>m) cntn++;
        else cntn--;

        prefn[cntn-1]=prefn[cntn-2]+ertn[cntn-1];
        ans-=prefn[cntn-1];
        ertn[cntn]++, prefn[cntn]=prefn[cntn-1]+ertn[cntn];
    }

    cout << ans << "\n";
    return 0;
}