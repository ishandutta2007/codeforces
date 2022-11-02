#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pairr;

int n,d[100],i,j,cnt;
vector<bool> been(100000), h(100);
bool flag = false;
vector<vector<bool>> w(26, vector<bool>(26));
vector<int> Graph[100];
vector<pairr> p;
string s[100000],answer[100];

int dfs(int v) {
    been[v] = true; cnt++;
    for(int i = 0; i < Graph[v].size(); i++){
        if(!been[Graph[v][i]]) dfs(Graph[v][i]);
    }
}

int dfs2(int v) {
    been[v] = true;
    answer[j] += char(v + 97);
    if(Graph[v].size() > 1) flag = true;
    for(int i = 0; i < Graph[v].size(); i++){
        if(!been[Graph[v][i]]) dfs2(Graph[v][i]);
        else flag = true;
    }
    return 1;
}

void printNO() {
	cout << "NO";
	exit(0);
}

bool compare(pairr a, pairr b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> s[i];
        fill(d, d + 30, 0);
        for(j = 0; j < s[i].size(); j++){
            d[s[i][j] - 97]++;
            if (j > 0) {
                if (!w[s[i][j - 1] - 97][s[i][j] - 97]) {
                    Graph[s[i][j - 1] - 97].push_back(s[i][j] - 97);
                    w[s[i][j - 1] - 97][s[i][j] - 97] = true;
                }
            }
        }
        for(j = 0; j < 26; j++) {
            if(d[j] > 1) printNO();
            if(d[j]) h[j] = 1;
        }
    }
 
    for(i = 0; i < 26; i++) {
        fill(been.begin(), been.begin() + 30, 0);
        cnt = 0;
        if (h[i]) {
            dfs(i);
            p.push_back(pairr(cnt, i));
        }
    }
    fill(been.begin(), been.begin() + 30, 0);
    sort(p.begin(), p.end(), compare); 
    j = 0;
    for(i = 0; i < p.size(); ++i) {
        if(!been[p[i].second]){
            if (!dfs2(p[i].second)) printNO();
            j++;
        }
    }
    if(flag) printNO();
    sort(answer, answer + j);
    for(i = 0; i < j; i++) cout << answer[i];
    return 0;
}