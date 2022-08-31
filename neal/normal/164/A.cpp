// #define NDEBUG
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const int MAX = 500005;
const int IGNORING = 0, ASSIGNING = 1, USING = 2;

int N, M, action[MAX];
vector<int> adj[MAX], radj[MAX];
bool assignable[MAX], usable[MAX];

void assign_dfs(int num)
{
    if (assignable[num])
        return;

    assignable[num] = true;

    for (int i = 0; i < (int) adj[num].size(); i++)
        assign_dfs(adj[num][i]);
}

void use_dfs(int num)
{
    if (usable[num])
        return;

    usable[num] = true;

    if (action[num] == ASSIGNING)
        return;

    for (int i = 0; i < (int) radj[num].size(); i++)
        use_dfs(radj[num][i]);
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
        scanf("%d", &action[i]);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    memset(assignable, false, sizeof(assignable));
    memset(usable, false, sizeof(usable));

    for (int i = 0; i < N; i++)
        if (action[i] == ASSIGNING)
            assign_dfs(i);

    for (int i = 0; i < N; i++)
        if (action[i] == USING)
            use_dfs(i);

    for (int i = 0; i < N; i++)
        printf("%d\n", assignable[i] && usable[i] ? 1 : 0);

    return 0;
}