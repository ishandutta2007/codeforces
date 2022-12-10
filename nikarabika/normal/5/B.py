import sys

def main():
    lines = sys.stdin.readlines()
    width = 0
    for line in lines:
        if line[-1] == '\n':
            line = line[:-1]
        width = max(width, len(line))
    print((width + 2) * '*')
    
    tmp = 0
    for line in lines:
        if line[-1] == '\n':
            line = line[:-1]
        l = len(line)
        rem = width - l
        lspc = (rem + tmp) // 2
        if rem % 2 == 1:
            tmp = 1 - tmp
        rspc = (rem + tmp) // 2
        print('*{}{}{}*'.format(lspc * ' ', line, rspc * ' '))
    print((width + 2) * '*')
    return 0


if __name__ == '__main__':
    exit(main())