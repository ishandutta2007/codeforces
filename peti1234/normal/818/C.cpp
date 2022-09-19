#include <bits/stdc++.h>

using namespace std;
int n, a, b;
int fel[100001];
int le[100001];
int jobb[100001];
int bal[100001];
int ofel[100001];
int ole[100001];
int ojobb[100001];
int obal[100001];
int main()
{
    cin >> n >> a >> b;
    for (int i=1; i<=n; i++) {
        int a, b, c, d;
        cin >> b >> a >> d >> c;
        fel[i]=min(a, c);
        ofel[fel[i]]++;
        le[i]=max(a, c);
        ole[le[i]]++;
        jobb[i]=max(b, d);
        ojobb[jobb[i]]++;
        bal[i]=min(b, d);
        obal[bal[i]]++;
    }
    for (int i=1; i<=max(a, b); i++) {
        ofel[i]+=ofel[i-1];
       // cout << ofel[i] << " ";
        obal[i]+=obal[i-1];
    }
    for (int i=max(a, b)-1; i>=1; i--) {
        ole[i]+=ole[i+1];
        ojobb[i]+=ojobb[i+1];
    }
    int b, j, f, l;
    cin >> b >> j >> f >> l;
    for (int i=1; i<=n; i++) {
        //cout << fel[i] << " " << le[i] << " " << jobb[i] << " " << bal[i] << endl;
        if (bal[i]==jobb[i]) {
            if (obal[jobb[i]-1]==b && ojobb[bal[i]+1]==j && ole[fel[i]+1]==l+1 && ofel[le[i]-1]==f+1) {
                cout << i << endl;
                return 0;
            }
        } else {
            if (obal[jobb[i]-1]==b+1 && ojobb[bal[i]+1]==j+1 && ole[fel[i]+1]==l && ofel[le[i]-1]==f) {
                cout << i << endl;
                return 0;
            }
        }
        if (i==2) {
            //cout << obal[jobb[i]-1] << " " << ojobb[bal[i]+1] << " " << ofel[le[i]+1] << " " <<ole[fel[i]-1] << endl;
        }
    }
    cout << -1 << endl;
    return 0;
}