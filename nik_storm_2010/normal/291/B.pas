var
    s,s1:ansistring; d,i:longint;


begin

  readln(s); d:=length(s); i:=1;
  while i<=d do
    begin
      if s[i]=' ' then inc(i) else
      begin
        if s[i]='"' then
        begin
          inc(i); s1:='';
          while s[i]<>'"' do
            begin
              s1:=s1+s[i]; inc(i);
            end;
          writeln('<',s1,'>'); inc(i);
        end
          else
        begin
          inc(i); s1:=s[i-1];
          while (i<=d) and (s[i]<>' ') do
            begin
              s1:=s1+s[i]; inc(i);
            end;
          writeln('<',s1,'>');
        end;
      end;
    end;

end.