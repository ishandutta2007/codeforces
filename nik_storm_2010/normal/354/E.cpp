#include<cstdio>
#include<memory.h>

using namespace std;
const int N = 25;
const int M = 10;

struct note { bool dp; int px, py, pz, x, y; };

int ans[N][M], a[N];
note w[N][M];

int main() {
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++) {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) w[i][j].dp = false;
        long long c;
        scanf("%I64d", &c);
        int cnt = 0;
        while (c != 0) {
            cnt++;
            a[cnt] = c % 10;
            c /= 10;
        }
        w[0][0].dp = true;
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
            if (!w[i][j].dp) continue;
            for (int x = 0; x <= 6; x++) for (int y = 0; y <= 6; y++) {
                int z = 6 - x - y;
                if (z < 0) continue;
                int sum = j + x * 7 + y * 4;
                if (sum % 10 != a[i + 1]) continue;
                w[i + 1][sum / 10].dp = true;
                w[i + 1][sum / 10].px = x;
                w[i + 1][sum / 10].py = y;
                w[i + 1][sum / 10].pz = z;
                w[i + 1][sum / 10].x = i;
                w[i + 1][sum / 10].y = j;
            }
        }
        if (!w[cnt][0].dp) printf("-1"); else {
            memset(ans, 0, sizeof(ans));
            int x, y, kx, ky, kz, i, j;
            x = cnt;
            y = 0;
            while (x != 0) {
                kx = w[x][y].px;
                ky = w[x][y].py;
                kz = w[x][y].pz;
                i = 1;
                while (kx != 0) { ans[x][i] = 7; kx--; i++; }
                while (ky != 0) { ans[x][i] = 4; ky--; i++; }
                i = w[x][y].x;
                j = w[x][y].y;
                x = i;
                y = j;
            }
            for (int i = 1; i <= 6; i++) {
                int nom = 1;
                for (int j = N - 1; j > 0; j--) if (ans[j][i] != 0) { nom = j; break; }
                for (int j = nom; j > 0; j--) printf("%d", ans[j][i]);
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}