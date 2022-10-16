#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <random>
#include <limits>
#include <string>
#include <sstream>
#include <functional>
#include <iomanip>

#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

class bohr
{
    struct node
    {
        size_t siz;
        node *par;
        bool end;

        vector<node *> nxt;

        node (node *par = nullptr) : nxt (128, nullptr), siz (0), par (par), end (false)
        {}

        ~node ()
        {
            for (auto it : nxt)
                if (it != nullptr)
                    delete it;
        }
    };

    using nodeptr = node * ;

    nodeptr curr = new node ();

public:
    int type (char c)
    {
        int eco = -2;

        if (curr->nxt[c] == nullptr)
        {
            if (curr->siz == 1 && curr->end)
            {
                nodeptr tmp = curr;

                while (tmp->siz == 1 && tmp->par != nullptr)
                {
                    eco++;
                    tmp = tmp->par;
                }
            }

            curr->nxt[c] = new node (curr);
        }

        curr = curr->nxt[c];

        return max (eco, 0);
    }

    int rewind ()
    {
        int eco = -2;

        if (curr->end)
            while (curr->par != nullptr)
            {
                if (curr->siz == 1)
                    eco++;

                curr = curr->par;
            }
        else
        {
            curr->end = true;

            while (curr->par != nullptr)
            {
                curr->siz++;
                curr = curr->par;
            }
        }

        return max (eco, 0);
    }
};

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int ans = 0, eco = 0;
    bohr boo;

    while (true)
    {
        string str;

        getline (cin, str);

        if (cin.eof ())
            break;

        str += '\n';

        for (auto it : str)
        {
            if (('A' <= it && it <= 'Z') ||
                ('a' <= it && it <= 'z'))
                eco += boo.type (it);
            else
                eco += boo.rewind ();

            ans++;
        }
    }

    cout << ans - eco << endl;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);

#ifdef LOCAL
    ifstream fin ("input.txt");

    solve (fin);

    cout << "clock: " << clock () << endl;
#else
    solve ();
#endif // LOCAL

    return 0;
}