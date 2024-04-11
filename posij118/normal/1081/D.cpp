#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k, distinct, w, y, z, cur, pos, nw, sz, kap;
    cin >> n >> m >> k;

    vector<int> comp[n];
    vector<int> g[n];
    int x[k];
    int invx[n];
    fill(invx, invx + n, -1);

    for(int i = 0; i<k; i++){
        cin >> x[i];
        x[i]--;
        invx[x[i]] = i;
    }

    int inv[n];
    int inv_selected[k];
    for(int i = 0; i<n; i++){
        inv[i] = i;
        comp[i].push_back(i);
    }

    for(int i = 0; i<k; i++){
        inv_selected[i] = x[i];
    }

    distinct = k - 1;

    pair<int, pair<int, int> > e[m];

    for(int i = 0; i<m; i++){
        cin >> y >> z >> w;
        e[i] = {w, {y - 1, z - 1}};
    }

    sort(e, e + m);

    for(int i = 0; i<m; i++){
        //cout << distinct << endl;
        if(inv[e[i].second.first] == inv[e[i].second.second]) continue;

        /*
            cout << endl;
        if(i == 1){
            for(int j = 0; j<n; j++){
                for(int k = 0; k<comp[j].size(); k++){
                    cout << "? ";
                    cout << comp[j][k] << " ";
                }

                cout << endl;
            }


        }
        */

        if(comp[inv[e[i].second.first]].size() > comp[inv[e[i].second.second]].size()){
            sz = comp[inv[e[i].second.second]].size();
            kap = inv[e[i].second.second];
            for(int j = 0; j<sz; j++){
                if(invx[comp[kap][j]] != -1){
                    cur = 0;
                    nw = 0;
                    pos = comp[kap][j];

                    if(invx[pos] == 0){
                        if(inv_selected[invx[pos]] != inv_selected[invx[pos] + 1]) cur++;
                    }

                    else if(invx[pos] == k - 1){
                        if(inv_selected[invx[pos]] != inv_selected[invx[pos] - 1]) cur++;
                    }

                    else{
                        if(inv_selected[invx[pos]] != inv_selected[invx[pos] + 1]) cur++;
                        if(inv_selected[invx[pos]] != inv_selected[invx[pos] - 1]) cur++;
                    }

                    inv_selected[invx[pos]] = inv[e[i].second.first];
                     //cout << inv_selected[0] << "  " << inv_selected[1] <<  " " << inv_selected[2] <<  endl;

                    if(invx[pos] == 0){
                        if(inv_selected[invx[pos]] != inv_selected[invx[pos] + 1]) nw++;
                    }

                    else if(invx[pos] == k - 1){
                        if(inv_selected[invx[pos]] != inv_selected[invx[pos] - 1]) nw++;
                    }

                    else{
                        if(inv_selected[invx[pos]] != inv_selected[invx[pos] + 1]) nw++;
                        if(inv_selected[invx[pos]] != inv_selected[invx[pos] - 1]) nw++;
                    }

                    distinct += nw - cur;


                }
                inv[comp[kap][j]] = inv[e[i].second.first];
                comp[inv[e[i].second.first]].push_back(comp[kap][j]);
            }
            comp[kap].clear();
        }

        else if(comp[inv[e[i].second.first]].size() <= comp[inv[e[i].second.second]].size()){
            sz = comp[inv[e[i].second.first]].size();
            kap = inv[e[i].second.first];
            for(int j = 0; j<sz; j++){
                if(invx[comp[kap][j]] != -1){
                    cur = 0;
                    nw = 0;
                    pos = comp[kap][j];

                    if(invx[pos] == 0){
                        if(inv_selected[invx[pos]] != inv_selected[invx[pos] + 1]) cur++;
                    }

                    else if(invx[pos] == k - 1){
                        if(inv_selected[invx[pos]] != inv_selected[invx[pos] - 1]) cur++;
                    }

                    else{
                        if(inv_selected[invx[pos]] != inv_selected[invx[pos] + 1]) cur++;
                        if(inv_selected[invx[pos]] != inv_selected[invx[pos] - 1]) cur++;
                    }
                    //cout << inv_selected[0] << "  " << inv_selected[1] <<  " " << inv_selected[2] <<  endl;
                    inv_selected[invx[pos]] = inv[e[i].second.second];


                    if(invx[pos] == 0){
                        if(inv_selected[invx[pos]] != inv_selected[invx[pos] + 1]) nw++;
                    }

                    else if(invx[pos] == k - 1){
                        if(inv_selected[invx[pos]] != inv_selected[invx[pos] - 1]) nw++;
                    }

                    else{
                        if(inv_selected[invx[pos]] != inv_selected[invx[pos] + 1]) nw++;
                        if(inv_selected[invx[pos]] != inv_selected[invx[pos] - 1]) nw++;
                    }

                    distinct += nw - cur;
                    //cout << cur << " " << nw << endl;
                    //cout << distinct << " CHANGED" << endl;

                }
                inv[comp[kap][j]] = inv[e[i].second.second];

                comp[inv[e[i].second.second]].push_back(comp[kap][j]);

            }
            comp[kap].clear();
        }
        //cout << i << endl;
        //cout << endl;

        if(distinct == 0){
            for(int j = 0; j<k; j++){
                cout << e[i].first << " ";
            }
            return 0;
        }
    }


}