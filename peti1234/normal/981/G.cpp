#include <bits/stdc++.h>

using namespace std;
const int c=1<<18, k=2*c;
int n, q, po=1;
int kezd[k], veg[k];
long long sum[k], lppr[k], lpsum[k], mod=998244353;
void init(int po) {
    for (int i=po; i<2*po; i++) {
        kezd[i]=i-po+1;
        veg[i]=i-po+1;
        lppr[i]=1;
    }
    for (int i=po-1; i>=1; i--) {
        kezd[i]=kezd[2*i], veg[i]=veg[2*i+1];
        lppr[i]=1;
    }
}
long long real(int a) {
    long long tav=(veg[a]-kezd[a]+1);
    return (sum[a]*lppr[a]+lpsum[a]*tav)%mod;
}
void calc(int a) {
    sum[a]=(real(2*a)+real(2*a+1))%mod;
}
void push(int a) {
    int x=2*a, y=2*a+1;
    lpsum[x]*=lppr[a], lpsum[x]%=mod;
    lpsum[x]+=lpsum[a], lpsum[x]%=mod;
    lpsum[y]*=lppr[a], lpsum[y]%=mod;
    lpsum[y]+=lpsum[a], lpsum[y]%=mod;
    lppr[x]*=lppr[a], lppr[x]%=mod;
    lppr[y]*=lppr[a], lppr[y]%=mod;
    lppr[a]=1;
    lpsum[a]=0;
}
void add(int a, int l, int r, bool op) {
    if (r<l) {
        return;
    }
    int bal=kezd[a], jobb=veg[a];
    if (bal>r || jobb<l) {
        return;
    }
    if (l<=bal && jobb<=r) {
        if (op) {
            lppr[a]*=2, lppr[a]%=mod;
            lpsum[a]*=2, lpsum[a]%=mod;
        } else {
            lpsum[a]++;
        }
        return;
    }
    push(a);
    add(2*a, l, r, op), add(2*a+1, l, r, op);
    calc(a);
}
long long ask(int a, int l, int r) {
    if (r<l) {
        return 0;
    }
    int bal=kezd[a], jobb=veg[a];
    if (bal>r || jobb<l) {
        return 0;
    }
    if (l<=bal && jobb<=r) {
        return real(a);
    }
    push(a);
    calc(a);
    return (ask(2*a, l, r)+ask(2*a+1, l, r))%mod;
}
set<pair<int, int> > s[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    while (po<n) {
        po*=2;
    }
    init(po);
    for (int i=1; i<=q; i++) {
        int id, l, r, x;
        cin >> id;
        if (id==1) {
            cin >> l >> r >> x;
            bool st=0, bk=1, jk=1;
            if (s[x].size()==0) {
                s[x].insert({0, 1});
                s[x].insert({k, 0});
            }
            auto bal=s[x].lower_bound({l, 0}), jobb=s[x].upper_bound({r, 1});
            bal--;
            pair<int, int> p=*bal;
            if (p.second==0) {
                st=1;
                bk=0;
            }
            p=*jobb;
            if (p.second==1) {
                jk=0;
            }
            int el=l;
            bal++;
            while (bal!=jobb) {
                int pos=(*bal).first-1+st;
                add(1, el, pos, st);
                st=!st;
                el=pos+1;
                auto torol=bal;
                bal++;
                s[x].erase(torol);
            }
            add(1, el, r, st);

            if (bk) {
                s[x].insert({l, 0});
            }
            if (jk) {
                s[x].insert({r, 1});
            }

        } else {
            cin >> l >> r;
            cout << ask(1, l, r) << "\n";
        }
    }
    return 0;
}