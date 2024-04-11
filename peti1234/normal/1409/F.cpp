#include <bits/stdc++.h>

using namespace std;
const int c=202;
int n, k, st[c], kom[c], cnt, maxi, db, sp, valt, f;
string a, b;
queue<int> q;
int main()
{
    cin >> n >> k >> a >> b;
    if (b[0]==b[1]) {
        int db=0;
        for (int i=0; i<n; i++) if (a[i]==b[0]) db++;
        db=min(db+k, n);
        cout << (db-1)*db/2 << "\n";
        return 0;
    }
    for (int i=0; i<=k; i++) for (int j=0; j<=i; j++) {
        while(q.size()>0) q.pop();
        for (int i=0; i<n; i++) {
            st[i]=0;
            if (a[i]==b[0]) st[i]=1;
            if (a[i]==b[1]) st[i]=2;
        }
        db=i, sp=j, cnt=0, valt=0, f=0;
        for (int i=0; i<n; i++) {
            if (st[i]==0 && db) db--, st[i]=1;
            if (st[i]==2 && db && sp) db--, sp--, st[i]=1;
        }
        for (int i=1; i<=n; i++) kom[i]=kom[i-1]+(st[i-1]==1);
        db=k-i;
        for (int i=n-1; i>=0; i--) {
            if (st[i]==2) cnt+=kom[i], f++;
            if (st[i]==1) q.push(kom[i]-f);
            if (st[i]==0) {
                while(db>0 && q.size()>0 && q.front()-valt>kom[i]) cnt+=q.front()-valt, db--, valt++, q.pop();
                if (db) cnt+=kom[i], f++, db--;
            }
        }
        while(db>0 && q.size()>0 && q.front()>valt) cnt+=q.front()-valt, db--, valt++, q.pop();
        maxi=max(maxi, cnt);
    }
    cout << maxi << "\n";
    return 0;
}