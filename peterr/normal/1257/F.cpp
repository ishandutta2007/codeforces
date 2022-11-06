#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int a[MAXN];

struct Node
{
    int x;
    Node* nxt[31];

    Node()
    {
        for (int i = 0; i <= 30; i++)
            nxt[i] = nullptr;
    }
};

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Node* root = new Node;
    for (int i = 0; i < (1 << 15); i++)
    {
        Node* curNode = root;
        for (int j = 0; j < n; j++)
        {
            int cur = a[j] & ((1 << 15) - 1);
            int cnt = __builtin_popcount(cur ^ i);
            if (curNode->nxt[cnt] == nullptr)
                curNode->nxt[cnt] = new Node;
            curNode = curNode->nxt[cnt];
        }
        curNode->x = i;
    }
    int ans = -1;
    for (int i = 0; i < (1 << 15); i++)
    {
        for (int target = 0; target <= 30; target++)
        {
            Node* curNode = root;
            for (int j = 0; curNode != nullptr && j < n; j++)
            {
                int cur = a[j] & (((1 << 15) - 1) << 15);
                int cnt = __builtin_popcount(cur ^ (i << 15));
                if (cnt > target)
                    curNode = nullptr;
                else
                    curNode = curNode->nxt[target - cnt];
            }
            if (curNode != nullptr)
                ans = (i << 15) | curNode->x;
        }
    }
    cout << ans << endl;
    return 0;
}