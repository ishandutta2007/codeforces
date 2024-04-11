uses math; const first='BitLGM'; second='BitAryo';
var
    f:array[0..300,0..300] of byte; n,i,j,k,a,b,c:longint;


begin

  readln(n);
  if n=1 then
    begin
      readln(a);
      if a=0 then writeln(second) else writeln(first);
    end;
  if n=2 then
    begin
      readln(a,b);
      for i:=0 to a do
        for j:=0 to b do
        begin
          for k:=1 to min(i,j) do if f[i-k,j-k]=0 then f[i,j]:=1;
          for k:=1 to max(i,j) do
            if ((i-k>=0)and(f[i-k,j]=0)) or ((j-k>=0)and(f[i,j-k]=0)) then f[i,j]:=1;
        end;
      if f[a,b]=0 then writeln(second) else writeln(first);
    end;
  if n=3 then
    begin
      readln(a,b,c);
      if (a xor b xor c)=0 then writeln(second) else writeln(first);
    end;

end.