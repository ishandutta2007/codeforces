import sys

def main():
    lines = sys.stdin.readlines()
    members = set()
    ans = 0
    for line in lines:
        if line[-1] == '\n':
            line = line[:-1]
        if line[0] == '+':
            members.add(line[1:])
        elif line[0] == '-':
            members.remove(line[1:])
        else:
            ans += len(line.split(':')[1]) * len(members)
    print(ans)
    return 0


if __name__ == '__main__':
    exit(main())