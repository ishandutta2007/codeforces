var
    a:array[1..8,1..4] of char; right,test,left,nom,pst,d,i,j,n:longint; s:string;


begin


  readln(n);
  for test:=1 to n do
    begin
      for i:=1 to 8 do for j:=1 to 4 do a[i,j]:='0';
      readln(s); s:=':'+s+':'; d:=length(s); nom:=d;
      for i:=2 to d-2 do
        if (s[i]=':') and (s[i]=s[i+1]) then
        begin
          nom:=i; break;
        end;
      left:=1; right:=8; i:=2;
      while i<=nom do
        begin
          j:=i; while s[j]<>':' do inc(j);
          for pst:=j-1 downto i do a[left,5-(j-pst)]:=s[pst];
          i:=j+1; inc(left);
        end;
      i:=d-1;
      while i>nom do
        begin
          j:=i; while s[j]<>':' do dec(j);
          for pst:=i downto j+1 do a[right,4-(i-pst)]:=s[pst];
          i:=j-1; dec(right);
        end;

      for i:=1 to 8 do
        begin
          for j:=1 to 4 do write(a[i,j]);
          if i<>8 then write(':');
        end;
      writeln;
    end;

end.