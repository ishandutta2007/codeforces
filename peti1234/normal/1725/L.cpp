#include <bits/stdc++.h>

using namespace std;

/*
figyelni kell a c, hossz, fen[] valtozokra
talan meg lehet optimalizalni
tobbszor is meghivhato
*/


const int c=500005;

int hossz, fen[c];
int lsb(int a) {
    return (a & -a);
}
void add(int a, int b) {
    while (a<=hossz) {
        fen[a]+=b;
        a+=lsb(a);
    }
}
long long ask(int a) {
    long long ans=0;
    while (a) {
        ans+=fen[a];
        a-=lsb(a);
    }
    return ans;
}

long long count_inversions(vector<long long> v) {
    hossz=v.size();
    long long ans=0;
    vector<pair<long long, int> > sz;
    int cnt=0;
    for (auto x:v) {
        sz.push_back({x, ++cnt});
    }
    sort(sz.rbegin(), sz.rend());
    for (auto x:sz) {
        int pos=x.second;
        ans+=ask(pos);
        add(pos, 1);
    }
    for (int i=0; i<=hossz; i++) {
        fen[i]=0;
    }
    return ans;

}
int main()
{
    int n;
    long long sum=0, maxi=0;
    vector<long long> sz;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        sum+=x;
        maxi=max(maxi, sum);
        if (sum<0) {
            cout << -1 << "\n";
            return 0;
        }
        sz.push_back(sum);
    }
    if (sum!=maxi) {
        cout << -1 << "\n";
        return 0;
    }
    cout << count_inversions(sz) << "\n";
    return 0;
}