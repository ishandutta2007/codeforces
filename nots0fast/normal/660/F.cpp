#include<bits/stdc++.h>
// #include <ext/pb_ds/aSoc_container.hpp>
// using namespace __gnu_pbds;
// #pragma GCC target ("avx,avx2,fma")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define SPEED ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define rall(v) (v).rbegin(),(v).rend()
#define all(v) (v).begin(),(v).end()
#define setp fixed<<setprecision
#define OK cerr<<"OK"<<endl<<flush
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define y0 jahdakdh
#define y1 jahsadakdakdh
#define endl '\n'
const ll MOD=1e9+7;
const ll mod=(1ll<<31)-1;
const ld eps=1e-8;
const ll inf=2*1e12;
using namespace std;
mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());

struct line{
    ll k, b;
    line(){
        
    }
    line(ll k1, ll b1){
        k = k1, b = b1;
    }
};

struct srt{
    const bool operator() (const ll& a,const ll& b ) const{
        return a > b;
    }   
};

void merge(ld& a1, ld& b1, ld a2, ld b2){
    a1 = min(a1, a2);
    b1 = max(b1, b2);
}

ld sect(line& a1, line& a2){
    ld k1 = a1.k, b1 = a1.b, k2 = a2.k, b2 = a2.b;
    
    // k1 * x + b1 = y
    // k2 * x + b2 = y
    
    // (k2 - k1) * x + (b2 - b1) = 0
    
    // x = (b1 - b2) / (k2 - k1)
     
    ld x =  (b1 - b2) / (k2 - k1);
    
    return x;
}

struct minHull{
    map< ll, tuple<line, ld, ld> , srt  > all;
    map<ld , line> ranges;
    
    void insert(line& cur){
        if(all.empty()){
            all.insert(make_pair(cur.k, make_tuple(cur, -inf, inf)));
            ranges.insert(make_pair(-inf, cur));
            return;
        }
        
        ld lef = inf, rig = -inf;
        
        auto it = all.lower_bound(cur.k);
        // k-si verilmish duz xettin k-sindan kicik beraber olan ilk duz xett
        
        if(it != all.end() && (*it).F == cur.k){
            auto[line2, a2, b2] = (*it).S;
            if(line2.b <= cur.b){
                return;
            }
            else{
                auto itn = it;
                ++itn;
                
                merge(lef, rig, a2, b2);
                ranges.erase(a2);
                all.erase(it);
                
                it = itn;
            }
        }
        
        
        if(it == all.end()){
            rig = inf;
        }
        while(it != all.end()){
            auto itn = it;
            ++itn;
            
            auto& [line2, l2, r2] = (*it).S;
            
            ld pt = sect(cur, line2);
            
            if(pt >= r2){
                merge(lef, rig, l2, r2);
                ranges.erase(l2);
                all.erase(it);
                it = itn;
            }
            else{ 
                if(pt > l2){
                    merge(lef, rig, l2, pt);
                    ranges.erase(l2);
                    l2 = pt;
                    ranges[l2] = line2;
                }
                break;
            }
        }
        
        
        
        
        if(it == all.begin()){
            lef = -inf;
        }
        while(it!=all.begin()){
            --it;
            auto& [line2, l2, r2] = (*it).S;
        
            ld pt = sect(cur, line2);
            
        //  cout<<"we are here point is "<<pt<<endl;
            
            if(pt <= l2){
                merge(lef, rig, l2, r2);
                auto ita = it;
                ++ita;
                ranges.erase(l2);
                all.erase(it);
                it = ita;
            }
            else{
                if(pt < r2){
                    merge(lef, rig, pt, r2);
                    r2 = pt;
                }
                break;
            }
        }
        
        
        if(lef < rig){
            all.insert(make_pair(cur.k, make_tuple(cur, lef, rig)));
            ranges.insert(make_pair(lef, cur));
        }
    }
    
    ll que(ll x){
        // en azi bir duz xett var
        auto it = ranges.upper_bound(x);
        --it;
        auto& ln = (*it).S;
        return 1ll*ln.k * x + ln.b;
    }
    
    void display(){
        cout<<"lines sorted by k "<<endl;
        for(auto& el : all){
            auto [ln, l, r] = el.S;
            cout<<"range "<<l<<" "<<r<<" line.K "<<ln.k<<"   line.B "<<ln.b<<endl;
        }
    }
};

int main()
{
    SPEED;
    int n;
    cin>>n;
    ll pr[n+5], prs[n+5];
    pr[0]=prs[0]=0;
    for(ll i=1; i<=n; i++)
    {
        ll x; cin>>x;
        pr[i]=pr[i-1]+x;
        prs[i]=prs[i-1]+x*i;
    }

    minHull all;
    
    ll ans=0;

    line yeni(0, 0);
    all.insert(yeni);
    

    for(ll j=1; j<=n; j++)
    {
       
        ans=max(ans, prs[j]-all.que(pr[j]));
        line yeni(j, prs[j]-j*pr[j]);
        all.insert(yeni);
    }
    cout<<ans<<endl;
    return 0;
}

// prs[i] = sum of a[i]*i in range [1...i];
// pr[i] = sum of a[i] in range [1...i];

// for every j maximize (0 <= i < j) :
// prs[j] - prs[i] - i * (pr[j] - pr[i])
// prs[j] - prs[i] - i*pr[j] + i*pr[i]
// prs[j] - (i*pr[j] + prs[i] - i*pr[i])
// k = i
// b = prs[i]-i*pr[i]
// ans = max(prs[j] + minHull(pr[j]));