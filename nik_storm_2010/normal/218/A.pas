var
    a:array[1..250] of longint; n,k,i:longint;


begin

  readln(n,k); for i:=1 to (n*2)+1 do read(a[i]);
  for i:=1 to n do
    begin
      if (a[i*2-1]<a[i*2]-1) and (a[i*2]-1>a[i*2+1]) and (k>0
      ) then
        begin
          dec(k); dec(a[i*2]);
        end;
    end;
  for i:=1 to (n*2)+1 do write(a[i],' ');

end.