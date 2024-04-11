#include <cstdio>
#include <vector>

const int v=62*62;

using namespace std;

vector<int> edge[v];
int eind[v];

bool numeric(char x) { return '0'<=x && x<='9';}
bool capital(char x) { return 'A'<=x && x<='Z';}
int convconv(char a) { return numeric(a)?(a-48+52):(capital(a)?(a-'A'):(a-'a'+26)); }
char rev(int x) { return x>=52?(x-52+'0'):((x>=26)?(x-26+'a'):(x+'A')); }
int conv(char a,char b) { return convconv(a)*62+convconv(b); }

int inode[v];
int onode[v];

int history[200010];
int top;

void dfs(int pos) {
    int &i=eind[pos];
    for(;i<edge[pos].size();) ++i,dfs(edge[pos][i-1]);
    history[top++]=pos;
}

int main()
{
    int n;
    scanf("%d",&n);
    int i,a,b; char buf[5];
    for(i=0;i<n;++i) scanf("%s",buf),edge[a=conv(buf[0],buf[1])].push_back(b=conv(buf[1],buf[2])), ++inode[b], ++onode[a];
    int outer=-1, samer=-1;
    for(i=0;i<v;++i) {
        if(onode[i]==inode[i]+1) {
            if(outer!=-1) {
                puts("NO");
                return 0;
            } else outer=i;
        } else {
            if(onode[i]==inode[i] && onode[i]){
                samer=i;
            }
        }
    }
    if(outer!=-1) dfs(outer);
    else if(samer!=-1) dfs(samer);
    else {
        puts("NO");
        return 0;
    }
    if(top != n+1){
        puts("NO");
        return 0;
    }
    puts("YES");
    putchar(rev(history[top-1]/62));
    putchar(rev(history[top-1]%62));
    for(i=top-2;0<=i;--i) putchar(rev(history[i]%62));
    return 0;
}