var
    s:array[1..2000] of string[100]; a:array[96..122,1..2000] of longint;
     kol,tek,k,i,d,j,c,n,y:longint; st:string[100]; sim:char;


begin

  readln(k); readln(st); d:=length(st);
  for i:=1 to d do
    begin
      c:=ord(st[i]);
      for j:=1 to k do inc(a[c,j]);
    end;
  for i:=1 to k do begin s[i]:=st; a[96,i]:=d; end;

  readln(n);
  for i:=1 to n do
    begin
      read(kol); read(sim); read(sim); c:=ord(sim); tek:=0;
      for j:=1 to k do
        if tek+a[c,j]>=kol then
          begin
            for y:=1 to a[96,j] do
              if s[j,y]=sim then
              begin
                inc(tek);
                if tek=kol then
                begin
                  delete(s[j],y,1); dec(a[c,j]);
                  dec(a[96,j]); break;
                end;
              end;
            break;
          end
            else
          begin
            tek:=tek+a[c,j];
          end;
    end;
  for i:=1 to k do write(s[i]);

end.