#include <bits/stdc++.h>

using namespace std;
long long n, p;
long long t[100005];

void merge_sort(long long t[], int a, int b)
{
    if (a==b) {
        return;
    }
    int k=(a+b)/2;
    merge_sort(t, a, k);
    merge_sort(t, k+1, b);
    vector<int> r;
    int x=a;
    int y=k+1;
    for (int i=1; i<=b-a+1; i++) {
        if (y>b  ||  (x<=k && t[x]<t[y])) {
            r.push_back(t[x]);
            x++;

        }
        else {
            r.push_back(t[y]);
            y++;
        }

    }
    for (int i=0; i<r.size(); i++) {
        t[a+i]=r[i];
    }
}


int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    merge_sort (t,1,n);
    for (int i=1; i<=n; i++) {
        p=(long long)(p+t[i]*t[n+1-i])%10007;
    }

    cout << p << endl;
    return 0;
}