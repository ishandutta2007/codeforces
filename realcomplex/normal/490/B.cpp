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

const int MAXN = 1e6+5;

int l[MAXN],r[MAXN];

void ini(){
    for(int j = 0;j<MAXN;j++){
        l[j] = j;
        r[j] = j;
    }
}

main(){
    //open();
    ini();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int a,b;
    for(int j = 0;j<n;j++){
        cin >> a >> b;
        l[a] = b;
        r[b] = a;
    }
    int s = 0;
    vector<int>la,ra;
    if(n%2==0){
        s = 0;
        while(l[s] != s){
            s = l[s];
            la.push_back(s);
        }
        s = 0;
        while(r[s]!=s){
            s = r[s];
            ra.push_back(s);
        }
    }
    else{
        s = 0;
        do{
            s = l[s];
            la.push_back(s);
        }while(s!=0);
        for(int j = 0;j<MAXN;j++)if(l[j] == j && r[j] != j) s = j;
        while(s!=r[s]){
            ra.push_back(s);
            s = r[s];
        }
        ra.push_back(s);
    }
    reverse(ra.begin(),ra.end());
    for(int j = 0;j<n;j++){
        if(j%2==0) cout << ra[j/2] << " ";
        else cout << la[j/2] << " ";
    }
    return 0;
}