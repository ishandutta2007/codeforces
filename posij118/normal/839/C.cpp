#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, x, a;
    long double sum;
    cin >> n;

    vector<int> vert[n+1];
    int edge[n-1][2];
    for(int i=0; i<n-1; i++){
        cin >> edge[i][0] >> edge[i][1];
        vert[edge[i][0]].push_back(edge[i][1]);
        vert[edge[i][1]].push_back(edge[i][0]);
    }

    long double res[n+1];
    res[1]=0;

    bool used[n+1];
    fill(used, used + n + 1, 0);
    vector<int> open;
    int rem[n+1];

    for(int i=1; i<n+1; i++){
        rem[i]=vert[i].size();
        if(i!=1){
            rem[i]--;
            if(rem[i]==0) open.push_back(i);
        }
    }

    while(open.size()>0){
        x=open[open.size()-1];
        open.pop_back();
        used[x]=1;
        a=0;
        sum=0;
        for(int i=0; i<vert[x].size(); i++){
            if(used[vert[x][i]]==1){
                a++;
                sum+=res[vert[x][i]];
            }

            else{
                    rem[vert[x][i]]--;
                if(rem[vert[x][i]]==0) open.push_back(vert[x][i]);
            }

        }

        if(a==0) res[x]=0;
        else res[x]=1+sum/a;
    }

    cout << setprecision(15) << res[1];
}