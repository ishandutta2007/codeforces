#include <bits/stdc++.h>

using namespace std;
int t[22];
int n;
int x=1;
int step;
vector<int> q;
int main()
{
    cin >> n;
    while(n>0) {
        if (n%2==1) {
            t[x]=1;
        }
        x++;
        n/=2;
    }
    x--;
    while(true) {
        bool v=false;
        for (int i=x; i>=1; i--) {
            if (t[i]==0 && !v) {
                q.push_back(i);
                v=true;
            }
            if (v) {
                t[i]++;
                t[i]%=2;
            }
        }
        if (!v) {
            break;
        }
        step++;
        int a=1;
        while(t[a]==1 && a<=x) {
            t[a]=0;
            a++;
        }
        t[a]=1;
        if (a>x) {
            break;
        }
        step++;
    }
    cout << step << endl;
    for (int i=0; i<q.size(); i++) {
        cout << q[i] << " ";
    }
    return 0;
}