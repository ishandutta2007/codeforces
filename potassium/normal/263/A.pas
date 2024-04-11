uses math;

var n,i,j    : longint;
    cnt,ans  : longint;
    a        : array[1..1000] of longint;
    s        : ansistring;
    b        : boolean;

begin
     for i := 1 to 5 do
     begin
          for j := 1 to 5 do
          begin
               read(cnt);

               if cnt = 1
               then ans := abs(3-i)+abs(3-j);
          end;
          readln;
     end;

     writeln(ans);
end.