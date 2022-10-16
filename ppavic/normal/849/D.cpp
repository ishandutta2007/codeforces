#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 500;

vector < int > x[2* N + 590];

vector < int > y[2* N + 590];

int a[2 * N +500],t[2 * N+ 500],g[2 * N + 500],ed[2 * N + 500],n,w,h;

bool cmp(int A, int B){
    return a[A] < a[B];
}

void dod(){
    for(int i = 0;i<n;i++){
        if(g[i]){
            y[t[i] - a[i] + N].push_back(i);
        }
        else{
            x[t[i] - a[i] + N].push_back(i);
        }
    }
}

void obradi(){ // wink wink
    for(int i = 0;i < 2 * N;i++){
        if(!x[i].size() && !y[i].size()) continue;
        if(x[i].size() + y[i].size() == 1){
            if(x[i].size()){
                ed[x[i][0]] = x[i][0];
            }
            else{
                ed[y[i][0]] = y[i][0];
            }
        }
        sort(x[i].begin(),x[i].end(),cmp);
        sort(y[i].begin(),y[i].end(),cmp);
        int kol = 0;
        for(int j = 0;j<x[i].size();j++){
            if(j + y[i].size() < x[i].size()){
                ed[x[i][j]] = x[i][j + y[i].size()];
            }
            else{
                ed[x[i][j]] = y[i][ x[i].size() - j - 1  ];
                kol++;
            }
        }
        kol = 0;
        for(int j = 0;j<y[i].size();j++){
            if(j + x[i].size() < y[i].size()){
                ed[y[i][j]] = y[i][j + x[i].size()];
            }
            else{
                ed[y[i][j]] = x[i][ y[i].size() - j - 1  ];
                kol++;
            }
        }
    }

}


int main(){
    scanf("%d %d %d",&n,&w,&h);
    for(int i = 0;i<n;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        g[i] = x - 1;
        a[i] = y;
        t[i] = z;
    }
    dod();obradi();
    for(int i = 0;i<n;i++){
        int wh = ed[i];
        if(g[wh]){
            printf("%d %d\n",w,a[wh]);
        }
        else{
            printf("%d %d\n",a[wh],h);
        }
    }
}