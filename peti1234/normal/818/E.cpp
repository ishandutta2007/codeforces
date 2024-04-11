#include <bits/stdc++.h>

using namespace std;
int n, k;
int t[100001];
map <int, int> p;
map <int, int> m;
int main()
{
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    if (k==1) {
        cout << (long long)n*(n+1)/2 << endl;
        return 0;
    }
    for (int i=2; i<=sqrt(k); i++) {
        int a=0;
        while (k%i==0){
            a++;
            k/=i;
        }
        if (a!=0) {
            p.insert(make_pair(i,a));
        }
    }
    if (k!=1) {
        p[k]=1;
    }
    int o=0;
    for(pair<int,int> elem : p) {
        m[elem.first]=0;
        o++;
    }
    long long q=0;
    int a=1, b=0;
    while (b<n+1) {
        //cout << o << endl;
        if (o!=0) {
            b++;
            if (b>n) {
                break;
            }
            int x=t[b];
            for (pair<const int, int>& i : m) {
                while (x%i.first==0){
                    x/=i.first;
                    i.second++;
                    if (i.second==p[i.first]) {
                        o--;
                    }
                }
            }
        } else {
            //cout << "a" << " " ;
            a++;
            q+=n+1-b;
            int x=t[a-1];
            for (pair<const int, int>& i : m) {
                while (x%i.first==0){
                    x/=i.first;
                    if (i.second==p[i.first]) {
                        o++;
                    }
                    i.second--;

                }
            }
        }
    }
    cout << q << endl;
    return 0;
}