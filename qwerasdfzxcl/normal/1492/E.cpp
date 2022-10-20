#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<vector<int>> matrix;
vector<int> arr;
pair<int, int> comb[6]={{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};
pair<int, int> comb2[6]={{0, 1}, {0, 2}, {1, 0}, {1, 2}, {2, 0}, {2, 1}};
int n, m;

int chk(bool flag){
    int ret=0, mx=0;
    for (int i=0;i<n;i++){
        int cnt=0;
        for (int j=0;j<m;j++) if (arr[j]!=matrix[i][j]) cnt++;
        if (flag){
            if (cnt>=4) return -1;
            else if (cnt==3){
                bool flag2=1;
                for (int j=0;j<m;j++) if (arr[j]==-1){
                    flag2=0; arr[j]=matrix[i][j];
                }
                if (flag2) return -1;
            }
            continue;
        }
        if (cnt>=5) return -1;
        else if (cnt>2 && cnt>mx){
            ret=i;
            mx=cnt;
        }
    }
    return ret;
}

vector<int> comp(int idx1, int idx2){
    vector<int> ret;
    for (int i=0;i<m;i++) if (matrix[idx1][i]!=matrix[idx2][i]) ret.push_back(i);
    return ret;
}

void solve(int idx, vector<int> &v){
    for (int z=0;z<6;z++){
        int c1=v[comb2[z].first], c2=v[comb2[z].second];
        for (int pos:v){
            if(c1==pos) arr[pos]=matrix[0][c1];
            else if (c2==pos) arr[pos]=matrix[idx][c2];
            else arr[pos]=-1;
        }
        if (chk(1)==0){
            printf("Yes\n");
            for (int x:arr){
                if (x!=-1) printf("%d ", x);
                else printf("1 ");
            }
            return;
        }
    }
    printf("No\n");
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i=0;i<n;i++){
        vector<int> v;
        matrix.push_back(v);
        for (int j=0;j<m;j++){
            int tmp;
            scanf("%d", &tmp);
            matrix[i].push_back(tmp);
        }
    }
    arr=matrix[0];
    int idx=chk(0);
    if (idx==-1){
        printf("No\n");
        return 0;
    }
    else if (idx==0){
        printf("Yes\n");
        for (int x:arr) printf("%d ", x);
        return 0;
    }
    vector<int> v=comp(0, idx);
    if ((int)v.size()==3){
        solve(idx, v);
        return 0;
    }
    for (int z=0;z<6;z++){
        int c1=v[comb[z].first], c2=-1;
        if ((int)v.size()>comb[z].second) c2=v[comb[z].second];
        for (int pos:v){
            if (c1==pos || c2==pos) arr[pos]=matrix[idx][pos];
            else arr[pos]=matrix[0][pos];
        }
        if (chk(0)==0){
            printf("Yes\n");
            for (int x:arr) printf("%d ", x);
            return 0;
        }
    }
    printf("No\n");
    return 0;
}