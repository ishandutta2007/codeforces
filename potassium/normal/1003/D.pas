program Codeforces;

var
    i,j            : longint;

    x              : longint;

    n,q            : longint;
    a              : array[0..32] of longint;

    query          : longint;
    required       : array[-1..32] of longint;
    total          : longint;

function log2(x : longint) : longint;

begin
     if x = 1
     then exit(0)
     else exit(log2(x div 2) + 1);
end;

function power2(x : longint) : longint;
var n : longint;
begin
     if x = 0
     then exit(1);

     if x = 1
     then exit(2);

     n := power2(x div 2);
     if x mod 2 = 0
     then exit(n*n)
     else exit(n*n*2);
end;

begin
     readln(n,q);

     for i := 0 to 32 do
         a[i] := 0;

     for i := 1 to n do
     begin
          read(x);
          inc(a[log2(x)]);
     end;

     for i := 1 to q do
     begin
          readln(query);

          for j := -1 to 32 do
              required[j] := 0;

          for j := log2(query) downto 0 do
              if query >= power2(j)
              then begin
                        inc(required[j]);
                        dec(query,power2(j));
                   end;

          for j := 32 downto 0 do
              if required[j] > a[j]
              then begin
                        inc(required[j-1],(required[j]-a[j])*2);
                        required[j] := a[j];
                   end;

          if required[-1] > 0
          then writeln(-1)
          else begin
                    total := 0;
                    for j := 32 downto 0 do
                        inc(total,required[j]);
                    writeln(total);
               end;
     end;

     readln;
end.