#include <cstdio>
#include <queue>
using namespace std;

typedef pair<int,int> P;

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    while (tc--) {
        int n;
        scanf("%d\n",&n);
        char s[51];
        char t[51];
        gets(s);
        gets(t);
        int count[26];
        for(int i=0;i<26;i++) {
            count[i]=0;
        }
        for(int i=0;i<n;i++) {
            count[s[i]-'a']+=1;
            count[t[i]-'a']+=1;
        }
        bool flag=true;
        for(int i=0;i<26;i++) {
            if (count[i]%2!=0) {
                flag=false;
                break;
            }
        }
        if (!flag) {
            printf("No\n");
            continue;
        }
        queue<P> q;
        int ret=0;
        for (int i=0;i<n;i++) {
            if (s[i]!=t[i]) {
                for(int j=i+1;j<n;j++) {
                    if (s[i]==s[j]) {
                        q.push(P(j,i));
                        ret+=1;
                        char temp=t[i];
                        t[i]=s[j];
                        s[j]=temp;
                        break;
                    }
                }
                if (s[i]!=t[i]) {
                    for(int j=i+1;j<n;j++) {
                        if (s[i]==t[j]) {
                            q.push(P(j,j));
                            ret+=1;
                            char temp=t[j];
                            t[j]=s[j];
                            s[j]=temp;
                            q.push(P(j,i));
                            ret+=1;
                            temp=t[i];
                            t[i]=s[j];
                            s[j]=temp;
                            break;
                        }
                    }
                }
            }
        }
        printf("Yes\n%d\n",ret);
        while (!q.empty()) {
            printf("%d %d\n",q.front().first+1,q.front().second+1);
            q.pop();
        }
    }
    return 0;
}