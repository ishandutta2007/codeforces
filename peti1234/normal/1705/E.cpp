#include <bits/stdc++.h>

using namespace std;
int n, m, t[250005], db[250005];
priority_queue<int> nagy, kis;
void valt(int pos) {
    int f=(db[pos]/2);
    if (f) {
        db[pos]-=2*f;
        db[pos+1]+=f;
        valt(pos+1);
        valt(pos);
    }
    if (db[pos]*db[pos+1]==-1) {
        db[pos]=db[pos+1];
        db[pos+1]=0;
        valt(pos);
    }
    if (db[pos]*db[pos-1]==-1) {
        db[pos-1]=db[pos];
        db[pos]=0;
        valt(pos-1);
    }
    if (db[pos]>0) {
        nagy.push(pos);
    }
    if (db[pos]<0) {
        kis.push(pos);
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    kis.push(-1), nagy.push(-1);
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        db[t[i]]++;
        valt(t[i]);
    }
    while (m--) {
        int pos, ert;
        cin >> pos >> ert;
        db[t[pos]]--;
        valt(t[pos]);
        t[pos]=ert;
        db[ert]++;
        valt(ert);



        while (nagy.top()>-1 && db[nagy.top()]<=0) {
            nagy.pop();
        }
        int x=nagy.top(), y, kov;

        while (kis.top()>-1 && db[kis.top()]>=0) {
            kis.pop();
        }
        nagy.pop();
        while (nagy.top()==x || (nagy.top()>-1 && db[nagy.top()]<=0)) {
            nagy.pop();
        }
        y=kis.top(), kov=nagy.top();
        nagy.push(x);

        /*for (int i=1; i<=n; i++) {
            cout << t[i] << " ";
        }
        cout << "\n";
        for (int i=1; i<=10; i++) {
            cout << db[i] << " ";
        }
        cout << "\n";
        cout << "fontos " << x << " " << y << " " << kov << "\n";*/

        cout << x-(y>kov) << "\n";


    }
    return 0;
}
/*
5 1
2 2 2 4 5
2 3
*/