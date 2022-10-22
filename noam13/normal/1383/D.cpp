#include <bits/stdc++.h>
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;

void finish(){
    printf("-1\n");
    exit(0);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m; 
    scanf("%d%d",&n,&m);
    vi row(n), col(m);
    loop(i,0,n) loop(j,0,m){
        int x; scanf("%d",&x);
        chkmax(row[i], x);
        chkmax(col[j], x);
    }
    sort(all(row)); sort(all(col));
    reverse(all(row)); reverse(all(col));
    int i=0, j=0;
    vvi ans(n, vi(m,-1));
    vi bef(n), aft(n);
    loop(xxx,0,n*m){
        int num=n*m-xxx;
        //cout<<"NUM: "<<num<<endl;
        bool x=(i<n && row[i]==num), y=(j<m && col[j]==num);
        if (x && y){
            bef[i] = aft[i] = j;
            ans[i++][j++] = num;
        }
        else if (x){
            if (j==0) finish();
            bef[i] = aft[i] = j - 1;
            ans[i++][j-1] = num;
        }
        else if (y){
            if (i==0) finish();
            ans[i-1][j++] = num;
        }
        else{
            bool found=0;
            loop(k,0,i){
                if (1){
                    int &r = aft[k];
                    while(r<j && ans[k][r]!=-1) r++;
                    if(r<j && ans[k][r]==-1 && (k==n-1 || ans[k+1][r]!=-1)){
                        ans[k][r] = num;
                        found = 1;
                        r++;
                        break;
                    }
                }
                if (1){
                    int &r = bef[k];
                    while(r>=0 && ans[k][r]!=-1) r--;
                    if(r>=0 && ans[k][r]==-1  && (k==0|| ans[k-1][r]!=-1)){
                        ans[k][r] = num;
                        r--;
                        found = 1;
                        break;
                    }
                }
            }
            if (!found) finish();
        }
    }
    loop(i,0,n) {loop(j,0,m) printf("%d ", ans[i][j]); printf("\n");}
    return 0;
}
/*
color a
cls
g++ d.cpp -o a & a
3 4
12 10 8 6
3 4 5 7
2 11 9 1

*/