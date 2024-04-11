#include <cstdio>
#include <set>

char map[52][52];
int n,m;
std::set<char> s;

int main()
{
    scanf("%d%d",&n,&m);
    int i,j;
    for(i=0;i<n;++i) scanf("%s",map[i]);
    int ans=0;
    for(i=0;i<n-1;++i){
        for(j=0;j<m-1;++j){
            s.insert(map[i][j]);
            s.insert(map[i][j+1]);
            s.insert(map[i+1][j]);
            s.insert(map[i+1][j+1]);
            if(
               s.find('f')!=s.end() &&
               s.find('a')!=s.end() &&
               s.find('c')!=s.end() &&
               s.find('e')!=s.end()
               ){
                ++ans;
            }
            s.clear();
        }
    }
    printf("%d\n",ans);
    return 0;
}