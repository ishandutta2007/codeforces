#include <cstdio>

char adj[26][26];
char bef[110];
char cur[110];

int inode[26];
bool dead[26];

int main()
{
    int n;
    scanf("%d",&n);
    --n;
    scanf("%s",bef);
    int i;
    for(;n--;){
        scanf("%s",cur);
        for(i=0;bef[i]==cur[i];++i);
        if(cur[i]==0 && bef[i]!=0){
            puts("Impossible");
            return 0;
        }
        if(bef[i] && cur[i] && !adj[bef[i]-'a'][cur[i]-'a'])
        adj[bef[i]-'a'][cur[i]-'a']=1,
        ++inode[cur[i]-'a'];
        for(i=0;cur[i];++i) bef[i]=cur[i];
        bef[i]=0;
    }
    int j,k;
    char ans[27];
    for(i=0;i<26;++i){
        for(j=0;j<26;++j) if(!dead[j] && inode[j]==0) break;
        if(j==26){
            puts("Impossible");
            return 0;
        }
        dead[j]=true;
        ans[i]=('a'+j);
        for(k=0;k<26;++k) if(adj[j][k]) --inode[k];
    }
    ans[26]=0;
    puts(ans);
    return 0;
}