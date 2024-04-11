#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

int ask(vector<int> lf, vector<int> rg){
    cout<<"? "<<lf.size()<<" "<<rg.size()<<endl;
    fflush(stdout);

    for(int x : lf) cout<<x<<" ";
    cout<<endl;
    fflush(stdout);

    for(int x : rg) cout<<x<<" ";
    cout<<endl;
    fflush(stdout);

    int x; cin>>x;
    return x;
}

void solve(){
    vector<int> zeros;
    int n; cin>>n;

    int lo = 1;
    int hi = lo;
    int ID;
    while(true){
        hi++;
        vector<int> pop = {};
        for(int i=1;i<hi;i++) pop.pb(i);
        int ac = ask(pop, {hi});

        if(ac != 0){
            hi--;
            ID = hi + 1;
            break;
        }
    }
    // [LO ... HI] mamy dokladnie 1 rozwalony, ID JEST SPECIALNY
    for(int i = ID + 1;i <= n; ++i){
        int ac = ask({ID}, {i});
        if(ac == 0) zeros.pb(i);
    }

    int wa = -1;

    while(lo + 1 < hi){
        int mid = (lo + hi) / 2;
        vector<int> pop;
        for(int i=lo;i<=mid;i++) pop.pb(i);
        int ac = ask(pop, {ID});
        if(ac != 0) hi = mid;
        else lo = mid + 1;
    }

    if(lo != hi){
        int ac = ask({lo}, {ID});
        if(ac != 0) wa = lo;
        else wa = hi;
    }
    else wa = lo;
    for(int i=1;i<=ID-1;i++){
        if(i != wa) zeros.pb(i);
    }

    cout<<"! "<<zeros.size()<<" ";
    for(int x : zeros) cout<<x<<" ";
    cout<<endl;
    fflush(stdout);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}