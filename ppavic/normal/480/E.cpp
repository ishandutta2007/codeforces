#include <cstdio>
#include <queue>
#include <deque>

using namespace std;

const int N = 2055;

int up[N][N], down[N][N], ans = 0, a[N][N], rev[N][2], sol[N], n, m, q;

struct moque{
    queue < int > q;
    deque < int > d;
    void push(int x){
        q.push(x);
        while(!d.empty() && d.back() > x) d.pop_back();
        d.push_back(x);
    }
    void pop(){
        if(q.front() == d.front())
            d.pop_front();
        q.pop();
    }
    int mini(){
        if(d.empty()) return 0;
        return d.front();
    }
};

void solve(int x) {
    moque upp, downn;
    int j = -1;
    for(int i = 0;i<m;i++){
        while(j < m && j - i + 1 <= upp.mini() + downn.mini()) {
            j++;
            if(j == m) break;
            upp.push(up[x][j]);
            downn.push(down[x][j]);
        }
        upp.pop();
        downn.pop();
        ans = max(ans, (j - i) * (!a[x][i]));
    }
}

void calc_up(int j){
    for(int i = 0;i<n;i++){
        up[i][j] = 0;
        if(a[i][j])
            up[i][j] = -1;
        else if(i > 0)
            up[i][j] = up[i - 1][j];
        up[i][j]++;
    }
}

void calc_down(int j){
    for(int i = n - 1;i >= 0;i--){
        down[i][j] = down[i + 1][j];
        if(!a[i + 1][j] && i + 1 < n )
            down[i][j]++;
        if(a[i][j])
            down[i][j] = 0;

    }
}

void precompute(){
    for(int j = 0;j<m;j++){
        calc_up(j);calc_down(j);
    }
    for(int i = 0;i<n;i++){
        solve(i);
    }
}

void dodaj(int x,int y){
    a[x][y] = 0;
    calc_up(y);
    calc_down(y);
    solve(x);
}

int main(){
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            char c;scanf(" %c", &c);
            a[i][j] = (c == 'X');
        }
    }
    for(int i = 0;i<q;i++){
        scanf("%d%d", &rev[i][0], &rev[i][1]);
        a[rev[i][0] - 1][rev[i][1] - 1] = 1;
    }
    precompute();
    for(int i = q - 1; i >= 0; i--){
        sol[i] = ans;
        dodaj(rev[i][0] - 1, rev[i][1] - 1);
    }
    //printf("ANS : %d\n", ans);
    for(int i = 0;i<q;i++)
        printf("%d\n", sol[i]);
}