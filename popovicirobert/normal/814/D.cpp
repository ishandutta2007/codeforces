#include <bits/stdc++.h>
#define MAXN 1000

struct Circle {
    double x;
    double y;
    double r;
    bool operator <(const Circle &other) const {
        return r > other.r;
    }
}v[MAXN + 1];

int lvl[MAXN + 1];
std::vector <int> g[MAXN + 1];

inline double dist(double x1, double y1, double x2, double y2) {
   return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

const double pi = 3.14159265359;

inline double aria(double r) {
   return pi * r * r;
}

double ans = 0;

bool viz[MAXN + 1];

void dfs(int nod) {
    viz[nod] = 1;
    if(lvl[nod] == 1 || lvl[nod] == 2)
       ans += aria(v[nod].r);
    else if(lvl[nod] % 2 == 1)
       ans -= aria(v[nod].r);
    else
       ans += aria(v[nod].r);
    for(auto it : g[nod])
       if(!viz[it])
          dfs(it);
}

int main() {
    FILE * fi, * fout;
    int i, n, j;
    //fi = fopen("F.in" ,"r");
    //fout = fopen("F.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d" ,&n);
    for(i = 1; i <= n; i++)
      fscanf(fi,"%lf%lf%lf" ,&v[i].x, &v[i].y, &v[i].r);
    std::sort(v + 1, v + n + 1);
    for(i = 1; i <= n; i++) {
      lvl[i] = 1;
      for(j = i - 1; j >= 1; j--)
        if(dist(v[i].x, v[i].y, v[j].x, v[j].y) < (v[i].r + v[j].r) * (v[i].r + v[j].r))
          lvl[i] = std::max(lvl[i], lvl[j] + 1);
      for(j = i - 1; j >= 1; j--)
        if(dist(v[i].x, v[i].y, v[j].x, v[j].y) <= (v[i].r + v[j].r) * (v[i].r + v[j].r) && lvl[i] == lvl[j] + 1)
          g[j].push_back(i);
    }
    for(i = 1; i <= n; i++)
       if(lvl[i] == 1)
          dfs(i);
    fprintf(fout,"%.9lf" ,ans);
    //fclose(fi);
   // fclose(fout);
    return 0;
}