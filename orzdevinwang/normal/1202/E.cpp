#include<bits/stdc++.h>
#define N 210000
using namespace std;
int n, tot[2], ch[2][N][26], fa[2][N], fail[2][N];
long long Ans, sum[2][N], ans[2][N];
void addfail(int m, char *f, int len) {
    int now = 0;
    for(int i = 0; i < len; i++) {
        if(!ch[m][now][f[i] - 'a']) ++tot[m], ch[m][now][f[i] - 'a'] = tot[m];
        now = ch[m][now][f[i] - 'a'];
    }
    sum[m][now]++;
}
void bfs(int m) {
    queue<int> q;
    sum[m][0] = 0;
    for(int i = 0; i < 26; i++) if(ch[m][0][i]) q.push(ch[m][0][i]);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < 26; i++) {
            int v = ch[m][u][i];
            if(!v) ch[m][u][i] = ch[m][fail[m][u]][i];
            else fail[m][v] = ch[m][fail[m][u]][i], q.push(v);
        }
        sum[m][u] += sum[m][fail[m][u]];
    }
}
void getans(int m, char *f, int len) {
    int now = 0;
    for(int i = 0; i < len; i++) now = ch[m][now][f[i] - 'a'], ans[m][i] = sum[m][now];
}
char a[N], s[N];
int main() {
    scanf("%s", a);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%s", s);
        int len = strlen(s);
        addfail(0, s, len), reverse(s, s + len), addfail(1, s, len);
    }
    int len = strlen(a);
    bfs(0), bfs(1),  getans(0, a, len), reverse(a, a + len), getans(1, a, len);
    reverse(ans[1],ans[1] + len);
    for(int i = 0; i < len - 1; i++) Ans += ans[0][i] * ans[1][i + 1];
    printf("%lld\n", Ans);
    return 0;
}

/*
srghfighrlydewwgajqqzqloxrahnlgzuxkdlpjjjldszzfhwngklqzmjvnvidxqwtoyyziipiymiextyebelxqmydplurhhzhviunbaxeeksyvhwdonntvtqqbayjkghztfwinstcjlipuqevojgqchakrzdzgfchrqpmnkmdnbabuitajmlvpflbdhlsyutvlirhhkdlwkcxxrlkddepihnwuhpizydsnpaqdgcudoduwiiswotipruyhkpqvdguwbeyaehelcnyyetbnhzlslolcpzdvwaxdropuqbicnjyvfztbiffujeqzyodizuomojfynjnjdwqlnmmghnwbztntztoiqzuzwxvzshoifkqlbzpdatkrupaiziptvpfofzgxzbvtzpvaksuvygvlmvmtrfdhggctohksyccsdggkitvuldyihkqxrmwtpjtkqntnaruznzwhreoiscciqiccxtsgtwyrvhkkhapklypcmthywdbcspeywehy
20
fa
afds
grwe
zv
as
s
d
we
ds
sd
f
qw
sfd
a
zv
af
we
qwp
fd
d
1000100000020000100000000010000000020000002200100000000000000200100000000000000000000000020000000000000100001000020000000001000000010001000000000000000010002001000000000200100001000001002001000000000020000000002200000000000022001020002020000100000000000002000000100000000000000010000002001020000000000001000011000000020000000100000200000000000000000000000000010001000000210000010000000101000000000010100000000000130000000010001300000000200000000000000000010000000000010000000001000000000010000000000020010000200
100010000002000010000000001000000002000000220010000000000000020000000000000000000000000002000000000000010000100002000000000100000001000100000000000000001000200100000000020010000100000100200100000000002000000000220000000000002200102000202000010000000000000200000010000000000000001000000200102000000000000100001100000002000000010000020000000000000000000000000001000100000021000001000000010100000000001010000000000013000000001000130000000020000000000000000001000000000001000000000100000000001000000000002001000010

0002000100200000000000100000000001000000000100000000000100000000000000000020000000022000100000000220000000000010100000000001010000000100000120000001000100000000000000000000000000020000010000000200000001100001000000000000201002000000100000000000000010000002000000000000010000202000201001300000000000022000000000200000000001002001000001000010020000000001002000100000000000000001000100000001000000000200001000010000000000000200000000000000000000000001020000000000000010013000000200000000100000000010000200000010001
*/