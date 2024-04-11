#include <bits/stdc++.h>

using namespace std;
const int c=(1<<19), sok=1e9+5;
int n, q, t[c];
set<int> s;

int kezd[c], veg[c];
long long fix[c], sum[c];

void init(int n) {
    int po=1;
    while (po<=n) {
        po*=2;
    }
    for (int i=po; i<2*po; i++) {
        kezd[i]=veg[i]=i-po;
    }
    for (int i=po-1; i>=1; i--) {
        kezd[i]=kezd[2*i], veg[i]=veg[2*i+1];
    }
}
int ss(int a, int l, int r) {
    if (kezd[a]>r || veg[a]<l) {
        return 0;
    }
    if (l<=kezd[a] && veg[a]<=r) {
        return 2;
    }
    return 1;
}

int push(int a) {
    int x=2*a, y=2*a+1;
    if (fix[a]) {
        fix[x]=fix[a], fix[y]=fix[a];
        sum[x]=sum[a]/2, sum[y]=sum[a]/2;
        fix[a]=0;
    }
}
void add(int a, int l, long long r) {
    int p=ss(a, l, r);
    if (p==0) {
        return;
    }
    if (p==2) {
        fix[a]=r;
        sum[a]=(veg[a]-kezd[a]+1)*r;
        return;
    }

    push(a);
    int x=2*a, y=2*a+1;
    add(x, l, r), add(y, l, r);
    sum[a]=sum[x]+sum[y];
}

long long ask(int a, int l, int r) {
    int p=ss(a, l, r);
    if (p==0) {
        return 0;
    }
    if (p==2) {
        return sum[a];
    }
    push(a);
    int x=2*a, y=2*a+1;
    sum[a]=sum[x]+sum[y];
    return ask(x, l, r)+ask(y, l, r);

}

void valt(int a, int b) {
    //cout << "valt " << a << " " << b << "\n";
    if (b==1) {
        s.insert(a);
        auto it=s.lower_bound(a);
        it--;
        add(1, (*it)+1, a);
    } else {
        s.erase(a);
        auto it=s.upper_bound(a), it2=it;
        it2--;
        add(1, (*it2)+1, *it);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    init(n);
    t[0]=sok;
    s.insert(0);
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        if (t[i]>t[i+1]) {
            valt(i, 1);
        }
    }
    for (int i=1; i<=q; i++) {
        int id;
        cin >> id;
        if (id==1) {
            int x, y;
            cin >> y >> x;
            if (t[y-1]>t[y] && t[y-1]<=x) valt(y-1, -1);
            if (t[y-1]<=t[y] && t[y-1]>x) valt(y-1, 1);
            if (t[y]>t[y+1] && x<=t[y+1]) valt(y, -1);
            if (t[y]<=t[y+1] && x>t[y+1]) valt(y, 1);
            t[y]=x;
        } else {
            long long l, r;
            cin >> l >> r;
            bool spec=0;
            if (s.find(r)==s.end()) {
                spec=1;
            }
            if (spec) {
                valt(r, 1);
            }
            long long ert=ask(1, l, r);
            if (spec) {
                valt(r, -1);
            }
            long long db=r-l+1;
            /*
            for (int i=1; i<=n; i++) {
                cout << t[i] << " ";
            }
            cout << "\n";
            */
            cout << ert-db*(l-1)-db*(db-1)/2 << "\n";
        }
    }

    return 0;
}