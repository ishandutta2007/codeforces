    #include <cstdio>
    #include <vector>
    using namespace std;
    int i,j,x,y,X,Y,n,m,r=1,md=1000003;
    char st[500100];
    vector <char> s[500100];
    int le(char c) { return c=='1' || c=='2'; }
    int up(char c) { return c=='1' || c=='4'; }
    int main() {
      scanf("%d%d",&n,&m);
      for (i=0; i<n; i++) {
        scanf("%s",st);
        for (j=0; j<m; j++) s[i].push_back(st[j]);
        for (j=0; j<m; j++) if (s[i][j]!='.') break;
        if (j>=m) {
          r+=r;
          if (r>=md) r-=md;
          continue;
        }
        x=le(s[i][j]); y=j&1;
        for (j++; j<m; j++) if (s[i][j]!='.') {
          X=le(s[i][j]); Y=j&1;
          if ((y==Y && x!=X) || (y!=Y && x==X)) { puts("0"); return 0; }
        }
      }
      for (j=0; j<m; j++) {
        for (i=0; i<n; i++) if (s[i][j]!='.') break;
        if (i>=n) {
          r+=r;
          if (r>=md) r-=md;
          continue;
        }
        x=up(s[i][j]); y=i&1;
        for (i++; i<n; i++) if (s[i][j]!='.') {
          X=up(s[i][j]); Y=i&1;
          if ((y==Y && x!=X) || (y!=Y && x==X)) { puts("0"); return 0; }
        }
      }
      printf("%d\n",r);
      return 0;
    }