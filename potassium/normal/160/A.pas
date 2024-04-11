uses math;

var n,m,p,q     : int64;
    l,r         : longint;
    i,j,k       : longint;
    x,y         : int64;
    cnt,ans     : int64;
    a           : array[1..100] of longint;
    s,s1,s2,c   : ansistring;
    b           : boolean;

procedure swap(var a,b : longint);

var t : longint;

begin
     t := a;
     a := b;
     b := t;
end;

begin
     readln(n);

     for i := 1 to n do
         read(a[i]);

     readln;

     for i := 1 to n-1 do
         for j := 1 to n-i do
             if a[j] < a[j+1]
             then swap(a[j],a[j+1]);

     ans := 0;

     for i := 1 to n do
         ans := ans + a[i];

     ans := ans div 2 + 1;

     cnt := 0;
     for i := 1 to n do
     begin
          cnt := cnt + a[i];
          if cnt >= ans
          then begin
                    writeln(i);
                    halt;
               end;
     end;
end.