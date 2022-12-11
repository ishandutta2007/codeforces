#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e12

void open(){
    freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}

string ap;
ll rb,rc,rs;
ll hasB,hasC,hasS;
ll cb,cc,cs;
ll cash = 0;
ll qb,qc,qs;
ll am;
bool can(ll k){
    qb = k*rb;
    qc = rc*k;
    qs = rs*k;
    cash = 0;
    if(qb>hasB)cash +=(qb-hasB)*cb;
    if(qc>hasC)cash +=(qc-hasC)*cc;
    if(qs>hasS)cash +=(qs-hasS)*cs;
    if(cash<=am){
        return true;
    }
    else{
        return false;
    }
}

ll l,r,m;

main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> ap;
    for(ll j = 0;j<ap.size();j++){
        if(ap[j] == 'B')rb++;
        else if(ap[j] == 'C')rc++;
        else rs++;
    }
    cin >> hasB >> hasS >> hasC;
    cin >> cb >> cs >> cc;
    cin >> am;
    l = 0,r = 1e14;
    while(r-l>1){
        m = (l+r)/2;
        if(can(m)) l = m;
        else r = m;
    }
    cout << l;
    return 0;
}