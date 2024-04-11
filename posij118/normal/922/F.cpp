#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, x, km, ptr, ii, y;
    km=0;
    cin >> n >> k;

    int pos[n+1];
    vector<int> div[n+1];
    for(int i=1; i<=n; i++){
        x=i;
        while(x<=n){
            div[x].push_back(i);
            x+=i;
        }
    }

    for(int i=1; i<n+1; i++){
        km+=div[i].size()-1;
    }

    if(k>km){
        cout << "No";
        return 0;
    }

    if(n<=21){
        int pow=1;
        for(int i=0; i<n; i++){
            pow*=2;
        }

        vector<int> used;
        for(int i=0; i<pow; i++){
            used.clear();
            ii=i;
            km=0;
            for(int j=1; j<=n; j++){

                if(ii%2) used.push_back(j);
                ii/=2;
            }

            for(int j=0; j<used.size(); j++){
                for(int k=j+1; k<used.size(); k++){
                    if(used[k]%used[j]==0) km++;
                }
            }

            if(km==k){
                cout << "Yes" << endl;
                cout << used.size() << endl;
                for(int j=0; j<used.size(); j++){
                    cout << used[j] << " ";
                }

                return 0;
            }
        }

        cout << "No";
    }

    else{

    vector<int> out;
    pair<int, int> rem[n+1];
    for(int i=1; i<=n; i++){
        rem[i]=make_pair(div[i].size()+n/i-2, i);
    }

    sort(rem+1, rem + n + 1);
    reverse(rem + 1, rem + n + 1);
    for(int i=1; i<=n; i++){
        pos[rem[i].second]=i;
    }

    ptr=0;

    while(km>k){

        if(km-rem[ptr+1].first>=k){
            km-=rem[ptr+1].first;
            rem[ptr+1].first=1e9;
            out.push_back(rem[ptr+1].second);
            for(int i=0; i<div[rem[ptr+1].second].size()-1; i++){
                rem[pos[div[rem[ptr+1].second][i]]].first--;
            }

            x=rem[ptr+1].second*2;
            while(x<=n){
                rem[pos[x]].first--;
                x+=rem[ptr+1].second;
            }
        }


        ptr=(ptr+1)%n;
        if(ptr==0) y++;
    }

    int in[n+1];
    fill(in, in + n + 1, 0);
    for(int i=0; i<out.size(); i++){
        in[out[i]]=1;
    }
    cout << "Yes" << endl;
    cout << n-out.size() << endl;
    for(int i=1; i<=n; i++){
        if(in[i]==0) cout << i << " ";
    }

    }
}