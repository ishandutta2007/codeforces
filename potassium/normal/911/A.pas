program NearestMinimum;

var n,i  : longint;
    a    : array[0..99999] of longint;
    min  : longint;
    last : longint;
    ans  : longint;

function minv(a,b : longint):longint;

begin
     if a >= b
     then minv := b
     else minv := a;
end;


begin
     readln(n);

     min := 2147483647;

     for i := 0 to n-1 do
     begin
          read(a[i]);
          if a[i] < min
          then min := a[i];
     end;

     last := -1;
     ans := 2147483647;

     for i := 0 to n-1 do
     begin
          if a[i] = min
          then begin
                    if (last > -1)
                    then ans := minv(ans, i-last);

                    last := i;
               end;
     end;

     writeln(ans);
end.