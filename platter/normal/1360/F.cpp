#include <bits/stdc++.h>
using namespace std;

char str[12][12];
vector<int> v[10][10];
char val[10][10];
int sz[10];
bool diff[10];
int n,m;
char ret[10];

bool track(int ind) {
    if (ind==m) {
        for(int i=0;i<m;i++) {
            printf("%c",ret[i]);
        }
        printf("\n");
        return true;
    }
    for(int i=0;i<sz[ind];i++) {
        bool flag=true;
        for(int j=0;j<v[ind][i].size();j++) {
            if (diff[v[ind][i][j]]) {
                flag=false;
            }
        }
        if (!flag) {
            continue;
        }
        for(int j=0;j<v[ind][i].size();j++) {
            diff[v[ind][i][j]]=true;
        }
        ret[ind]=val[ind][i];
        if (track(ind+1)) {
            return true;
        }
        for(int j=0;j<v[ind][i].size();j++) {
            diff[v[ind][i][j]]=false;
        }
    }
    return false;
}

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        memset(sz,0,sizeof(sz));
        for(int i=0;i<10;i++) {
            for(int j=0;j<10;j++) {
                v[i][j].clear();
            }
        }
        scanf("%d %d\n",&n,&m);
        for(int i=0;i<n;i++) {
            scanf("%s\n",str[i]);
        }
        int cnt=0;
        for(int j=0;j<m;j++) {
            vector<int> temp[26];
            for(int i=0;i<n;i++) {
                temp[str[i][j]-'a'].push_back(i);
            }
            for(int i=0;i<26;i++) {
                if (temp[i].size()!=0) {
                    val[j][sz[j]]='a'+i;
                    for(int k=0;k<26;k++) {
                        if (i!=k) {
                            for(int l=0;l<temp[k].size();l++) {
                                v[j][sz[j]].push_back(temp[k][l]);
                            }
                        }
                    }
                    sz[j]++;
                    cnt++;
                }
            }
            cnt--;
        }
        if (cnt>n) {
            printf("-1\n");
            continue;
        }
        memset(diff,0,sizeof(diff));
        if (!track(0)) {
            printf("-1\n");
        }
    }
}