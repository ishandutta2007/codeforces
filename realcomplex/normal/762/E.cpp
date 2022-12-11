#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct Station{
    int xpos;
    int rang;
    int freq;
    bool operator< (Station A){
        return xpos < A.xpos;
    }
};

const int K = (int)2e4 + 9;
priority_queue<pii, vector<pii>, greater<pii>> segs[K];
vector<int> lefs[K];
vector<int> segm[K];

void upd(int d, int z, int vl){
    z += (int)segm[d].size()/2;
    segm[d][z] += vl;
    z /= 2;
    while(z > 0){
        segm[d][z] += vl;
        z /= 2;
    }
}

int calc(int d, int l, int r){
    l += (int)segm[d].size()/2;
    r += (int)segm[d].size()/2;
    int sum = 0;
    while(l <= r){
        if(l%2 == 1) sum += segm[d][l ++ ];
        if(r%2 == 0) sum += segm[d][r -- ];
        l /= 2;
        r /= 2;
    }
    return sum;
}

int main(){
    fastIO;
    int n,k;
    cin >> n >> k;
    vector<Station> st;
    int xpos, rg, fq;
    for(int i = 0 ; i < n; i ++ ){
        cin >> xpos >> rg >> fq;
        st.push_back({xpos, rg, fq});
        segm[fq].push_back(0);
        segm[fq].push_back(0);
    }
    sort(st.begin(), st.end());
    int lf;
    ll answ = 0;
    for(int j = 0 ; j < st.size(); j ++ ){
        for(int bf = max(0, st[j].freq - k); bf <= st[j].freq + k; bf ++ ){

            while(!segs[bf].empty()){
                if(segs[bf].top().fi >= st[j].xpos)
                    break;
               upd(bf, segs[bf].top().se, -1);
               segs[bf].pop();
            }


            if(!lefs[bf].empty()){
                lf = lower_bound(lefs[bf].begin(), lefs[bf].end(), st[j].xpos - st[j].rang) - lefs[bf].begin();
                answ += calc(bf,lf,lefs[bf].size()-1);
            }

        }
        upd(st[j].freq, lefs[st[j].freq].size(), 1);
        segs[st[j].freq].push(mp(st[j].xpos + st[j].rang, lefs[st[j].freq].size()));
        lefs[st[j].freq].push_back(st[j].xpos);
    }
    cout << answ << "\n";
    return 0;
}