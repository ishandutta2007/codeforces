#include <cstdio>
#include <map>
using namespace std;

map<int,bool> dmap[200];
char data[200][200];
int n;
void ini(map<int,bool>* a,bool b){
    int i,j;
    for(i=-n+1;i<n;++i){
        for(j=-n+1;j<n;++j){
            a[n+i][j]=b;
        }
    }
}

char mydraw[200][200];

int main()
{
//    freopen("D:\\input.txt","r",stdin);
    scanf("%d",&n);
    int i,j;
    for(i=n-1;0<=i;--i) scanf("%s",data[i]);
    int a,b;
    ini(dmap,true);
    for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            if(data[i][j]=='o'){
                for(a=0;a<n;++a){
                    for(b=0;b<n;++b){
                        if(data[a][b]=='.') dmap[n+a-i][b-j]=false;
                    }
                }
            }
        }
    }
    for(i=0;i<n;++i){
        for(j=0;j<n;++j) {
            mydraw[i][j]='.';
        }
    }
    int nx,ny;
    for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            if(data[i][j]!='o') continue;
            for(a=-n+1;a<n;++a){
                for(b=-n+1;b<n;++b){
                    if(dmap[n+a][b]){
                        nx=i+a; ny=j+b;
                        if(0<=nx && 0<=ny && nx<n && ny<n){
                            mydraw[nx][ny]='x';
                        }
                    }
                }
            }
        }
    }
    for(i=0;i<n;++i){
        for(j=0;j<n;++j) {
            if(data[i][j]=='o') mydraw[i][j]='o';
            if(mydraw[i][j]!=data[i][j]){
                puts("NO"); return 0;
            }
        }
    }
    puts("YES");
    for(i=n-1;i>=-n+1;--i){
        for(j=-n+1;j<n;++j){
            if(i==0 && j==0) putchar('o');
            else if(dmap[n+i][j]) putchar('x');
            else putchar('.');
        }
        putchar(10);
    }
    return 0;
}