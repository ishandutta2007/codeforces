#include <cstdio>
#include <set>

using namespace std;

const int N = 2e5 + 500;

int loga[3][N], n, q, A[N], rev[N];
set < int > s[3];

void update(int x,int y,int k){
    x += 10;
    for(; x < N ; x += x & -x)
        loga[k][x] += y;
}

int query(int lo,int hi,int k){
    if(lo > hi) return 0;
    int ret = 0;
    lo += 9;hi += 10;
    for(; hi ; hi -= hi & -hi)
        ret += loga[k][hi];
    for(; lo ; lo -= lo & -lo)
        ret -= loga[k][lo];
    return ret;
}

int obradi(int x){      // x => papir
    int y = (x + 2) % 3; // y => kare
    int z = (x + 1) % 3; // z => kamen
    if(s[y].size() == 0) return (int)s[x].size();
    if(s[z].size() == 0) return 0;
    int ly = *s[y].begin(), ry = *s[y].rbegin();
    int lz = *s[z].begin(), rz = *s[z].rbegin();
    int ans = (int)s[x].size();
    ans -= query(ly, lz, x);
    ans -= query(rz, ry, x);
    //printf("X = %d ANS = %d\n", x, ans);
   // printf("Y [ %d %d ] Z [ %d %d ]\n", ly, ry, lz, rz);
    return ans;
}


int main(){
    rev['P'] = 1; rev['S'] = 0; rev['R'] = 2;
    scanf("%d%d", &n, &q);
    for(int i = 0;i<n;i++){
        char c;scanf(" %c", &c);
        A[i] = rev[c];
        update(i, 1, A[i]);
        s[A[i]].insert(i);
    }
    printf("%d\n", obradi(0) + obradi(1) + obradi(2));
    for(int i = 0;i<q;i++){
        int ind;int c;char x;
        scanf("%d %c", &ind, &x);
        ind--;c = rev[x];
        update(ind, -1, A[ind]);
        s[A[ind]].erase(ind);
        A[ind] = c;
        update(ind, 1, A[ind]);
        s[A[ind]].insert(ind);
        printf("%d\n", obradi(0) + obradi(1) + obradi(2));

    }
}