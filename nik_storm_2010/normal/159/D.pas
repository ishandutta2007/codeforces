uses math;
 var
    st:array[0..2001] of int64; pal:array[1..2000,1..2000] of byte;
     s:ansistring; answer:int64; i,l,r,d,j:longint;


begin

  readln(s); d:=length(s); s:=s+'$';
  for i:=1 to d do
    begin
      l:=i; r:=i; pal[l,r]:=1;
      while not((l=1) or (r=d)) do
        begin
          if s[l-1]=s[r+1] then
            begin
              dec(l); inc(r);
              pal[l,r]:=1;
            end
          else break;
        end;
      for j:=1 to i do inc(st[j],min(i-l+1,i-j+1));

      if s[i]=s[i+1] then
        begin
          l:=i; r:=i+1; pal[l,r]:=1;
          while not((l=1) or (r=d)) do
            begin
              if s[l-1]=s[r+1] then
                begin
                  dec(l); inc(r);
                  pal[l,r]:=1;
                end
              else break;
            end;
          for j:=1 to i do inc(st[j],min(i-l+1,i-j+1));
        end;
    end;

  answer:=0;
  for i:=1 to d do
    for j:=1 to d do
      if pal[i,j]=1 then answer:=answer + st[j+1];
  writeln(answer);

end.