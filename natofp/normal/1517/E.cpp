#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

const int mod = 998244353;
const int nax = 2e5 + 5;
ll a[nax];
ll prefix[nax];
int n;

ll prefix_np[nax];
ll prefix_p[nax];

ll sum_np(ll lo, ll hi){
    ll ans = prefix_np[hi];
    if(lo > 1) ans -= prefix_np[lo - 2];
    return ans;
}

ll sum_p(ll lo, ll hi){
    ll ans = prefix_p[hi];
    ans -= prefix_p[lo - 2];
    return ans;
}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    // jak male to sie potencjalnie cos rozjebie :DD
    prefix[0] = 0;
    prefix_p[0] = 0;
    prefix_np[1] = a[1];
    for(int i=2;i<=n;i++){
        if(i & 1) prefix_np[i] = prefix_np[i - 2] + a[i];
        else prefix_p[i] = prefix_p[i - 2] + a[i];
    }
    for(int i=1;i<=n;i++){
        prefix[i] = prefix[i - 1] + a[i];
    }

    ll ans = 0;
    for(int i=2;i<=n;i++){
        //i P na poczatku :D
        ll pre = prefix[i];
        ll suf = prefix[n] - prefix[i];
        if(suf < pre){
            ans++;
        }
    }
    //cout<<"WA"<<ans<<endl;
    // TU OK CHYBA
    // takie co maja CCC na poczatku, fixujemy ile + binsercz na sufix;
    for(int i=1;i<=n;i++){
        // czy sufix P parzysty czy nie
        // najpierw parzysty
        ll c_cost = prefix[i];
        int last_pos = n;

        for(int par=0;par<2;par++){
            bool dbg = (i == 1 && par == 0);
            if((i + par) % 2 == n % 2){
                c_cost = prefix[i];
                last_pos = n;
            }
            else{
                c_cost = a[n] + prefix[i];
                last_pos = n - 1;
            }
            int lo = 0;
            int hi = (last_pos - i) / 2;
            //if(dbg) cout << lo << " "<< hi<<endl;
            // LICZBA PAR (PC) ZA PREFIXEM
            // suma C * 2 < prefix[n]
            while(lo + 1 < hi){
                int mid = (lo + hi) / 2;
                ll bonus = 0;
                if(i & 1){
                    bonus = sum_np(i + 2, i + mid * 2);
                }
                else bonus = sum_p(i + 2, i + mid * 2);
                if((bonus + c_cost) * 2 < prefix[n]){
                    lo = mid;
                }
                else hi = mid;
            }
            int len = lo;
        //if(dbg) cout << "WA"<<len<<endl;
            ll bonus = 0;
            if(i & 1){
                bonus = sum_np(i + 2, i + hi * 2);
            }
            else bonus = sum_p(i + 2, i + hi * 2);
            if((bonus + c_cost) * 2 < prefix[n]) len = hi;
            //if(dbg) cout<<"AC"<<len<<" " <<bonus<<endl;
            if(c_cost * 2 >= prefix[n]) continue;
            if(i + len * 2 >= last_pos) len--;
            // jaka dlugosc jest ok? [0,1,2...len]
            ans += (len + 1);
            //cout << i << " " << par <<  " " << len << endl;
        }
        // sufix musi miec > 0 dlugosc :)
    }
    // JUZ PRAIWE JEST KURWA XD
    // DOTAD JEST MOZE DOBRZE
    //exit(0);
    //cout<<"WA"<<ans<<endl;
    // TUTAJ MOZE SIE JEBAC SUFIX ZE JEST 0


    for(int i=2;i<=n;i++){
        // czy sufix P parzysty czy nie
        // najpierw parzysty
        ll c_cost = prefix[i] - prefix[1];
        int last_pos = n;

        for(int par=0;par<2;par++){
            bool dbg = (i == 2 && par == 0);
            if((i + par) % 2 == n % 2){
                c_cost = prefix[i] - prefix[1];
                last_pos = n;
            }
            else{
                c_cost = a[n] + prefix[i] - prefix[1];
                last_pos = n - 1;
            }
            int lo = 0;
            int hi = (last_pos - i) / 2;
            //if(dbg) cout << lo << " "<< hi<<endl;
            // LICZBA PAR (PC) ZA PREFIXEM
            // suma C * 2 < prefix[n]
            while(lo + 1 < hi){
                int mid = (lo + hi) / 2;
                ll bonus = 0;
                if(i & 1){
                    bonus = sum_np(i + 2, i + mid * 2);
                }
                else bonus = sum_p(i + 2, i + mid * 2);
                if((bonus + c_cost) * 2 < prefix[n]){
                    lo = mid;
                }
                else hi = mid;
            }
            int len = lo;

        //if(dbg) cout << "WA"<<len<<endl;
            ll bonus = 0;
            if(i & 1){
                bonus = sum_np(i + 2, i + hi * 2);
            }
            else bonus = sum_p(i + 2, i + hi * 2);
            if((bonus + c_cost) * 2 < prefix[n]) len = hi;
            //if(dbg) cout<<"AC"<<len<<endl;
            //if(dbg) cout<<"AC"<<len<<" " <<bonus<<endl;
            if(c_cost * 2 >= prefix[n]) continue;

            // jaka dlugosc jest ok? [0,1,2...len]

            if(i + len * 2 >= last_pos) len--;
            ans += (len + 1);
            //cout << i << " " << par <<  " " << len << endl;
        }
        // sufix musi miec > 0 dlugosc :)
    }

    // PCCCCCCCCCC

    // PCCCCCCC

    if(n >= 1){
        if((prefix[n] - prefix[1]) * 2 < prefix[n]) ans++;
    }

    // TODO SUFIX DOUBLE COUNTING

    cout << ans % mod << "\n";
}

char xd[nax];

ll brute(){
    int odp = 0;
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i & (1<<j)) xd[j] = 'P';
            else xd[j] = 'C';
        }

        ll sum1 = 0;
        ll sum2 = 0;
        vector<int> pos1, pos2;
        for(int j=0;j<n;j++){
            if(xd[j] == 'P') pos2.pb(j);
            else pos1.pb(j);
        }
        int last = 0;
        bool ok = true;
        bool deb = (xd[0] == 'C' && xd[1] == 'P' && xd[2] == 'C' && xd[3] == 'P' && xd[4] == 'P');
        for(int j=1;j<pos1.size();j++){
            if(pos1[j] - pos1[j - 1] < last) ok = false;
            last = pos1[j] - pos1[j - 1];
        }
        //if(deb) cout<<"W"<<ok<<endl;
        last = 1e9;
        for(int j=1;j<pos2.size();j++){
            if(pos2[j] - pos2[j - 1] > last) ok = false;
            last = pos2[j] - pos2[j - 1];
        }
        if(!ok) continue;
        for(int j=0;j<n;j++){
            if(xd[j] == 'C') sum1 += a[j + 1];
            else sum2 += a[j + 1];
        }

        if(sum1 < sum2){
            odp++;
            for(int j=0;j<n;j++){
               // cout<<xd[j];
            }
            //cout<<"\n";
        }
    }
    cout<<odp<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
        //brute();
    }

    return 0;
}